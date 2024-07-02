#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "node.hpp"

template <typename T, int K = 2>
class Tree {
public:
Node<T>* root;

Tree() : root(nullptr) {}

~Tree() {
    delete_tree(root);
}

void add_root(T value) {
    root = new Node<T>(value);
}

void add_sub_node(Node<T>* parent, T value) {
    if (parent->children.size() >= K) {
        throw std::runtime_error("Maximum number of children reached");
    }
    Node<T>* child = new Node<T>(value);
    parent->add_child(child);
}

// Pre-Order Iterator
class PreOrderIterator {
private:
    std::stack<Node<T>*> stack;

public:
    PreOrderIterator(Node<T>* root) {
        if (root) stack.push(root);
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PreOrderIterator& other) const {
        return stack == other.stack;
    }

    PreOrderIterator& operator++() {
        if (!stack.empty()) {
            Node<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(*it);
            }
        }
        return *this;
    }

    Node<T>* operator*() const {
        if (!stack.empty()) {
            return stack.top();
        }
        return nullptr;
    }
};

PreOrderIterator begin_pre_order() const {
    return PreOrderIterator(root);
}

PreOrderIterator end_pre_order() const {
    return PreOrderIterator(nullptr);
}

//In-Order Iterator
class InOrderIterator {
private:
    std::stack<Node<T>*> stack;
    Node<T>* current;

public:
    InOrderIterator(Node<T>* root) : current(root) {
        if (root) {
            stack.push(root);
            current = root;
            while (!stack.empty() && current->children.size() > 0) {
                stack.push(current->children[0]);
                current = current->children[0];
            }
        }
    }

    bool operator!=(const InOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const InOrderIterator& other) const {
        return stack == other.stack;
    }

    InOrderIterator& operator++() {
        if (!stack.empty()) {
            Node<T>* node = stack.top();
            stack.pop();
            if (node->children.size() > 1) {
                stack.push(node->children[1]);
                current = node->children[1];
                while (!stack.empty() && current->children.size() > 0) {
                    stack.push(current->children[0]);
                    current = current->children[0];
                }
            }
        }
        return *this;
    }

    Node<T>* operator*() const {
        if (!stack.empty()) {
            return stack.top();
        }
        return nullptr;
    }
};

InOrderIterator begin_in_order() const {
    return InOrderIterator(root);
}

InOrderIterator end_in_order() const {
    return InOrderIterator(nullptr);
}


// PostOrderIterator class
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack;
    std::stack<bool> visited;
    Node<T>* current;

public:
    PostOrderIterator(Node<T>* root) : current(root) {
        if (root) {
            pushLeftMostNodes(root);
        }
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !(*this == other);
    }

    bool operator==(const PostOrderIterator& other) const {
        return stack.empty() && other.stack.empty();
    }

    PostOrderIterator& operator++() {
        if (stack.empty()) return *this;

        Node<T>* node = stack.top();
        stack.pop();
        visited.pop();

        if (!stack.empty() && !visited.top()) {
            visited.pop();
            visited.push(true);
            pushLeftMostNodes(stack.top()->children.back());
        }

        return *this;
    }

    Node<T>* operator*() const {
        return stack.empty() ? nullptr : stack.top();
    }

private:
    void pushLeftMostNodes(Node<T>* node) {
        while (node) {
            stack.push(node);
            visited.push(false);
            if (!node->children.empty()) {
                node = node->children[0];
            } else {
                node = nullptr;
            }
        }
    }
};

PostOrderIterator begin_post_order() const {
    return PostOrderIterator(root);
}

PostOrderIterator end_post_order() const {
    return PostOrderIterator(nullptr);
}

// BFS Iterator
class BFSIterator {
private:
std::queue<Node<T>*> queue;
std::unordered_set<Node<T>*> visited; 

public:
BFSIterator(Node<T>* root) {
    if (root) {
        queue.push(root);
        visited.insert(root);
    }
}

bool operator!=(const BFSIterator& other) const {
    return !queue.empty();
}

bool operator==(const BFSIterator& other) const {
    return queue == other.queue;
}

BFSIterator& operator++() {
    if (!queue.empty()) {
        Node<T>* node = queue.front();
        queue.pop();
        for (auto& child : node->children) {
            if (visited.find(child) == visited.end()) {
                queue.push(child);
                visited.insert(child);
            }
        }
    }
    return *this;
}

Node<T>* operator*() const {
    return queue.front();
}
};

BFSIterator begin_bfs_scan() const {
    return BFSIterator(root);
}

BFSIterator end_bfs_scan() const {
    return BFSIterator(nullptr);
}

// DFS Iterator
class DFSIterator {
private:
std::stack<Node<T>*> stack;
std::unordered_set<Node<T>*> visited; 

public:
DFSIterator(Node<T>* root) {
    if (root) {
        stack.push(root);
        visited.insert(root);
    }
}

bool operator!=(const DFSIterator& other) const {
    return !stack.empty();
}

bool operator==(const DFSIterator& other) const {
    return stack == other.stack;
}

DFSIterator& operator++() {
    if (!stack.empty()) {
        Node<T>* node = stack.top();
        stack.pop();
        for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
            if (visited.find(*it) == visited.end()) {
                stack.push(*it);
                visited.insert(*it);
            }
        }
    }
    return *this;
}

Node<T>* operator*() const {
    return stack.top();
}
};

DFSIterator begin_dfs_scan() const {
    return DFSIterator(root);
}

DFSIterator end_dfs_scan() const {
    return DFSIterator(nullptr);
}

void myHeap() {
if (K != 2) {
    throw std::runtime_error("Heap only supported for binary trees (K=2)");
}


std::vector<Node<T>*> nodes;
collect_nodes(root, nodes);


int n = nodes.size();
for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(nodes, n, i);
}


build_heap_tree(nodes);
}



void collect_nodes(Node<T>* node, std::vector<Node<T>*>& nodes) {
    if (!node) return;
    nodes.push_back(node);
    for (auto& child : node->children) {
        collect_nodes(child, nodes);
    }
}

void heapify(std::vector<Node<T>*>& nodes, int n, int i) {
int smallest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && nodes[left]->value < nodes[smallest]->value) {
    smallest = left;
}

if (right < n && nodes[right]->value < nodes[smallest]->value) {
    smallest = right;
}

if (smallest != i) {
    std::swap(nodes[i], nodes[smallest]);
    heapify(nodes, n, smallest);
}
}



// Build a heap tree from a vector of nodes
void build_heap_tree(std::vector<Node<T>*>& nodes) {
    if (nodes.empty()) {
    root = nullptr;
    return;
}


root = nodes[0];


for (size_t i = 0; i < nodes.size(); ++i) {
    Node<T>* parent = nodes[i];
    size_t leftChildIndex = 2 * i + 1;
    size_t rightChildIndex = 2 * i + 2;

    // Clear existing children before adding new ones
        parent->clear_children();

    if (leftChildIndex < nodes.size()) {
        parent->add_child(nodes[leftChildIndex]);
    }

    if (rightChildIndex < nodes.size()) {
        parent->add_child(nodes[rightChildIndex]);
    }
}
}


// Destructor to delete the entire tree
void delete_tree(Node<T>* node) {
    
    if (!node) return;

        for (Node<T>* child : node->children) {
            delete_tree(child);
        }

    delete node;
    
}
};

#endif // TREE_HPP

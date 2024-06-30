#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>
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
            if(K > 2)
                throw std::invalid_argument("PreOrderIterator work just on binary tree !");
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
                    stack.push(*it);  // Push raw pointer *it
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

    // BFS Iterator
    class BFSIterator {
    private:
        std::queue<Node<T>*> queue;

    public:
        BFSIterator(Node<T>* root) {
            if (root) queue.push(root);
        }

        bool operator!=(const BFSIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const BFSIterator& other) const {
            return queue == other.queue;
        }

        BFSIterator& operator++() {
            if (!queue.empty()) {
                Node<T>* node = queue.front();
                queue.pop();
                for (auto& child : node->children) {
                    queue.push(child);
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

    public:
        DFSIterator(Node<T>* root) {
            if (root) stack.push(root);
        }

        bool operator!=(const DFSIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const DFSIterator& other) const {
            return stack == other.stack;
        }

        DFSIterator& operator++() {
            if (!stack.empty()) {
                Node<T>* node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);  // Push raw pointer *it
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

// Post-Order Iterator (only for binary trees)
class PostOrderIterator {
private:
    std::stack<Node<T>*> stack;
    Node<T>* current;

public:
    PostOrderIterator(Node<T>* root) : current(root) {
        if(K > 2)
                throw std::invalid_argument("PostOrderIterator work just on binary tree !");
        if (root) {
            pushLeftMostNodes(root);
        }
    }

    bool operator!=(const PostOrderIterator& other) const {
        return stack != other.stack;
    }

    bool operator==(const PostOrderIterator& other) const {
        return stack == other.stack;
    }

    PostOrderIterator& operator++() {
        if (stack.empty()) return *this;

        current = stack.top();
        stack.pop();

        if (!stack.empty() && stack.top()->children.size() > 0 && current == stack.top()->children.front()) {
            pushLeftMostNodes(stack.top()->children.back());
        }

        return *this;
    }

    Node<T>* operator*() const {
        if (!stack.empty()) {
            return stack.top();
        }
        return nullptr;
    }

private:
    void pushLeftMostNodes(Node<T>* node) {
        while (node) {
            stack.push(node);
            if (!node->children.empty()) {
                node = node->children.front();
            } else {
                node = nullptr;
            }
        }
    }
};

// Function to get the beginning of PostOrderIterator
PostOrderIterator begin_post_order() const {
    return PostOrderIterator(root);
}

// Function to get the end of PostOrderIterator
PostOrderIterator end_post_order() const {
    return PostOrderIterator(nullptr);
}



    // In-Order Iterator (only for binary trees)
    class InOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        Node<T>* current;

    public:
        InOrderIterator(Node<T>* root) : current(root) {
             if(K > 2)
                throw std::invalid_argument("InOrderIterator work just on binary tree !");
            
            while (current) {
                stack.push(current);
                current = (current->children.empty()) ? nullptr : current->children[0];
            }
        }
        

        bool operator!=(const InOrderIterator& other) const {
            return stack != other.stack;
        }

        bool operator==(const InOrderIterator& other) const {
            return stack == other.stack;
        }

        InOrderIterator& operator++() {
            if (stack.empty()) return *this;

            current = stack.top();
            stack.pop();

            if (current->children.size() > 1) {
                current = current->children[1];
                while (current) {
                    stack.push(current);
                    current = (current->children.empty()) ? nullptr : current->children[0];
                }
            } else {
                current = nullptr;
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

    // Transform to min-heap (only for binary trees)
    void myHeap() {
        if (K != 2) {
            throw std::runtime_error("Heap transformation only supported for binary trees (K=2)");
        }

        std::vector<Node<T>*> nodes;
        collect_nodes(root, nodes);

        std::make_heap(nodes.begin(), nodes.end(), [](Node<T>* a, Node<T>* b) {
            return a->value > b->value; // For min-heap, the parent should be less than children
        });

        build_heap_tree(nodes);
    }

    // Collect all nodes in a vector
    void collect_nodes(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        for (auto& child : node->children) {
            collect_nodes(child, nodes);
        }
    }

    // Build a heap tree from a vector of nodes
    void build_heap_tree(std::vector<Node<T>*>& nodes) {
        if (nodes.empty()) {
            root = nullptr;
            return;
        }

        root = nodes[0];
        std::queue<Node<T>*> q;
        q.push(root);
        int index = 1;

        while (index < nodes.size()) {
            Node<T>* current = q.front();
            q.pop();
            current->children.clear(); // Clear existing children

            if (index < nodes.size()) {
                current->children.push_back(nodes[index++]);
                q.push(current->children.back());
            }

            if (index < nodes.size()) {
                current->children.push_back(nodes[index++]);
                q.push(current->children.back());
            }
        }
    }

    // Destructor to delete the entire tree
    void delete_tree(Node<T>* node) {
        if (!node) return;
        for (auto& child : node->children) {
            delete_tree(child);
        }
        delete node;
    }
};

#endif // TREE_HPP

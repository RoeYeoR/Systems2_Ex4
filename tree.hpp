#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <algorithm>
//#include <QMainWindow>
#include "node.hpp"

template <typename T, int K = 2>
class Tree {
public:
    std::shared_ptr<Node<T>> root;

    Tree() : root(nullptr) {}

    ~Tree() {
        delete_tree(root);
    }

    void add_root(T value) {
        root = std::make_shared<Node<T>>(value);
    }

    void add_sub_node(std::shared_ptr<Node<T>> parent, T value) {
        if (parent->children.size() >= K) {
            throw std::runtime_error("Maximum number of children reached");
        }
        auto child = std::make_shared<Node<T>>(value);
        parent->add_child(child);
    }

    // Pre-Order Iterator
    class PreOrderIterator {
    private:
        std::stack<std::shared_ptr<Node<T>>> stack;
    public:
        PreOrderIterator(std::shared_ptr<Node<T>> root) {
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
                auto node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }

        std::shared_ptr<Node<T>> operator*() const {
            return stack.top();
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
        std::queue<std::shared_ptr<Node<T>>> queue;
    public:
        BFSIterator(std::shared_ptr<Node<T>> root) {
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
                auto node = queue.front();
                queue.pop();
                for (auto& child : node->children) {
                    queue.push(child);
                }
            }
            return *this;
        }

        std::shared_ptr<Node<T>> operator*() const {
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
        std::stack<std::shared_ptr<Node<T>>> stack;
    public:
        DFSIterator(std::shared_ptr<Node<T>> root) {
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
                auto node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }

        std::shared_ptr<Node<T>> operator*() const {
            return stack.top();
        }
    };

    DFSIterator begin_dfs_scan() const {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() const {
        return DFSIterator(nullptr);
    }

    // Post-Order Iterator
    class PostOrderIterator {
    private:
        std::stack<std::shared_ptr<Node<T>>> stack;
        std::shared_ptr<Node<T>> last_visited;
        std::shared_ptr<Node<T>> current;
    public:
        PostOrderIterator(std::shared_ptr<Node<T>> root) : last_visited(nullptr), current(root) {
            while (current) {
                stack.push(current);
                if (!current->children.empty()) {
                    current = current->children.front();
                } else {
                    current = nullptr;
                }
            }
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !(*this == other);
        }

        bool operator==(const PostOrderIterator& other) const {
            return stack == other.stack && last_visited == other.last_visited;
        }

        PostOrderIterator& operator++() {
            if (!stack.empty()) {
                auto node = stack.top();
                if (!node->children.empty() && last_visited != node->children.back()) {
                    current = node->children.back();
                    while (current) {
                        stack.push(current);
                        if (!current->children.empty()) {
                            current = current->children.front();
                        } else {
                            current = nullptr;
                        }
                    }
                } else {
                    stack.pop();
                    last_visited = node;
                }
            }
            return *this;
        }

        std::shared_ptr<Node<T>> operator*() const {
            return stack.top();
        }
    };

    PostOrderIterator begin_post_order() const {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() const {
        return PostOrderIterator(nullptr);
    }

    // In-Order Iterator (only for binary trees)
    class InOrderIterator {
    private:
        std::stack<std::shared_ptr<Node<T>>> stack;
        std::shared_ptr<Node<T>> current;
    public:
        InOrderIterator(std::shared_ptr<Node<T>> root) : current(root) {
            while (current) {
                stack.push(current);
                if (!current->children.empty()) {
                    current = current->children.front();
                } else {
                    current = nullptr;
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
                auto node = stack.top();
                stack.pop();
                if (node->children.size() > 1) {
                    current = node->children[1];
                    while (current) {
                        stack.push(current);
                        if (!current->children.empty()) {
                            current = current->children.front();
                        } else {
                            current = nullptr;
                        }
                    }
                }
            }
            return *this;
        }

        std::shared_ptr<Node<T>> operator*() const {
            return stack.top();
        }
    };

    InOrderIterator begin_in_order() const {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() const {
        return InOrderIterator(nullptr);
    }

    // Transform to min-heap
    void myHeap() {
        if (K != 2) {
            throw std::runtime_error("Heap transformation only supported for binary trees (K=2)");
        }

        std::vector<std::shared_ptr<Node<T>>> nodes;
        collect_nodes(root, nodes);

        std::make_heap(nodes.begin(), nodes.end(), [](std::shared_ptr<Node<T>> a, std::shared_ptr<Node<T>> b) {
            return a->value < b->value;

        });

        build_heap_tree(nodes);
    }

    // Collect all nodes in a vector
    void collect_nodes(std::shared_ptr<Node<T>> node, std::vector<std::shared_ptr<Node<T>>>& nodes) {
        if (!node) return;
        nodes.push_back(node);
        for (auto& child : node->children) {
            collect_nodes(child, nodes);
        }
    }

    // Build a heap tree from a vector of nodes
    void build_heap_tree(std::vector<std::shared_ptr<Node<T>>>& nodes) {
        root = nodes[0];
        std::queue<std::shared_ptr<Node<T>>> q;
        q.push(root);
        int index = 1;
        while (index < nodes.size()) {
            auto current = q.front();
            q.pop();
            current->children.clear();
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
    void delete_tree(std::shared_ptr<Node<T>> node) {
        if (!node) return;
        for (auto& child : node->children) {
            delete_tree(child);
        }
        node.reset();
    }

//    // Printing Tree using GUI
//    void printTree(MainWindow& window) const {
//        window.updateTreeWidget(root);
//    }
};

#endif // TREE_HPP

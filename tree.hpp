#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <QMainWindow>
#include "node.hpp"

template <typename T, int K = 2>
class Tree {
public:
    std::shared_ptr<Node<T>> root;

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

    // Printing Tree using GUI
    void printTree(MainWindow& window) const {
        window.updateTreeWidget(root);
    }
};

#endif // TREE_HPP

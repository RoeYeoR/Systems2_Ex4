#include "doctest.h"
#include "tree.hpp" // Include your tree implementation header
#include "node.hpp"
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

TEST_CASE("Test PreOrderIterator on a binary tree") {
    Tree<int, 2> tree; // Binary tree (K = 2)
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    // Use the PreOrderIterator on a binary tree
    ostringstream oss;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        oss << (*it)->value << " ";
    }

    // Assert the traversal order
    CHECK(oss.str() == "1 2 3 ");
}

TEST_CASE("Test PreOrderIterator throws exception on a non-binary tree") {
    Tree<int, 3> tree; // Ternary tree (K = 3), non-binary
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);
    tree.add_sub_node(root, 4);

    // Attempt to use PreOrderIterator on a non-binary tree
    CHECK_THROWS_AS([&]() {
        for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
            // Do nothing, just iterate to trigger the exception
        }
    }(), std::invalid_argument);
}

TEST_CASE("Test InOrderIterator on a binary tree") {
    Tree<int, 2> tree; // Binary tree (K = 2)
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    // Use the InOrderIterator on a binary tree
    ostringstream oss;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        oss << (*it)->value << " ";
    }

    // Assert the traversal order
    CHECK(oss.str() == "2 1 3 ");
}

TEST_CASE("Test InOrderIterator throws exception on a non-binary tree") {
    Tree<int, 3> tree; // Ternary tree (K = 3), non-binary
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);
    tree.add_sub_node(root, 4);

    // Attempt to use InOrderIterator on a non-binary tree
    CHECK_THROWS_AS([&]() {
        for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
            // Do nothing, just iterate to trigger the exception
        }
    }(), std::invalid_argument);
}

TEST_CASE("Test PostOrderIterator on a binary tree") {
    Tree<int, 2> tree; // Binary tree (K = 2)
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    // Use the PostOrderIterator on a binary tree
    ostringstream oss;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        oss << (*it)->value << " ";
    }

    // Assert the traversal order
    CHECK(oss.str() == "2 3 1 ");
}

TEST_CASE("Test PostOrderIterator throws exception on a non-binary tree") {
    Tree<int, 3> tree; // Ternary tree (K = 3), non-binary
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);
    tree.add_sub_node(root, 4);

    // Attempt to use PostOrderIterator on a non-binary tree
    CHECK_THROWS_AS([&]() {
        for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
            // Do nothing, just iterate to trigger the exception
        }
    }(), std::invalid_argument);
}

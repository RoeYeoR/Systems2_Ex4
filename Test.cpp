#include "doctest.h"
#include "tree.hpp" 
#include "node.hpp"
#include "complex.hpp"
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
    std::ostringstream oss;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        oss << (*it)->get_value() << " ";
    }

   
    CHECK(oss.str() == "1 2 3 ");
}

TEST_CASE("Test InOrderIterator on a binary tree") {
    Tree<int, 2> tree; // Binary tree (K = 2)
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    // Use the InOrderIterator on a binary tree
    std::ostringstream oss;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        oss << (*it)->get_value() << " ";
    }

   
    CHECK(oss.str() == "2 1 3 ");
}

TEST_CASE("Test PostOrderIterator on a binary tree") {
    Tree<int, 2> tree; // Binary tree (K = 2)
    tree.add_root(1);
    auto root = tree.root;
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);

    // Use the PostOrderIterator on a binary tree
    std::ostringstream oss;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        oss << (*it)->get_value() << " ";
    }

  
    CHECK(oss.str() == "2 3 1 ");
}


TEST_CASE("Test myHeap() transformation on a binary tree") {
    Tree<int> tree; // Binary tree (K = 2)
    tree.add_root(5);
   
    tree.add_sub_node( tree.root, 7);
    tree.add_sub_node( tree.root, 2);

    
    auto leftNode =  tree.root->children[0];
    tree.add_sub_node(leftNode, 3);
    tree.add_sub_node(leftNode, 4);

    // Apply myHeap() transformation
    tree.myHeap();

    // Validate the tree after transformation
    std::ostringstream oss;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        oss << (*it)->get_value() << " ";
    }

    
    CHECK(oss.str() == "2 4 3 5 7 ");
}

TEST_CASE("Test traversal iterators on a binary tree after myHeap()") {
    Tree<int> tree; // Binary tree (K = 2)
    tree.add_root(5);
    
    tree.add_sub_node(tree.root, 7);
    tree.add_sub_node(tree.root, 2);

   
    auto leftNode = tree.root->children[0];
    tree.add_sub_node(leftNode, 3);
    tree.add_sub_node(leftNode, 4);

   
    tree.myHeap();
    
    // Validate PreOrderIterator
    std::ostringstream preOrderOss;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        preOrderOss << (*it)->get_value() << " ";
    }

    // Assert the pre-order traversal order
    CHECK(preOrderOss.str() == "2 4 5 7 3 ");

    // Validate InOrderIterator
    std::ostringstream inOrderOss;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        inOrderOss << (*it)->get_value() << " ";
    }

    
    CHECK(inOrderOss.str() == "5 4 7 2 3 ");

    // Validate PostOrderIterator
    std::ostringstream postOrderOss;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        postOrderOss << (*it)->get_value() << " ";
    }

    // Assert the post-order traversal order
    CHECK(postOrderOss.str() == "5 7 4 3 2 ");
}


TEST_CASE("Test DFSIterator on a K-ary tree (K = 3)") {
    Tree<int, 3> tree; // K-ary tree (K = 3)
    tree.add_root(1);
   
    tree.add_sub_node(tree.root, 2);
    tree.add_sub_node(tree.root, 3);
    tree.add_sub_node(tree.root, 4);

    // Adding more nodes for depth
    auto node2 = tree.root->children[0];
    tree.add_sub_node(node2, 5);
    tree.add_sub_node(node2, 6);
    tree.add_sub_node(node2, 7);

    // Use the DFSIterator on a K-ary tree
    std::ostringstream oss;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        oss << (*it)->get_value() << " ";
    }

   
    CHECK(oss.str() == "1 2 5 6 7 3 4 ");

    CHECK_THROWS(tree.myHeap());

    
}


TEST_CASE("Test BFSIterator on a K-ary tree (K = 3)") {
    Tree<int, 3> tree; // K-ary tree (K = 3)
    tree.add_root(1);
   
    tree.add_sub_node(tree.root, 2);
    tree.add_sub_node(tree.root, 3);
    tree.add_sub_node(tree.root, 4);

    // Adding more nodes for depth
    auto node2 = tree.root->children[0];
    tree.add_sub_node(node2, 5);
    tree.add_sub_node(node2, 6);
    tree.add_sub_node(node2, 7);

    // Use the BFSIterator on a K-ary tree
    std::ostringstream oss;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        oss << (*it)->get_value() << " ";
    }

   
    CHECK(oss.str() == "1 2 3 4 5 6 7 ");

    CHECK_THROWS(tree.myHeap());

    
}

TEST_CASE("Test BFSIterator on a K-ary complex tree (K = 3)") {
    Tree<Complex, 3> tree; // K-ary complex tree (K = 3)
    tree.add_root(Complex(1, 2));
    
    tree.add_sub_node(tree.root, Complex(3, 4));
    tree.add_sub_node(tree.root, Complex(5, 6));
    tree.add_sub_node(tree.root, Complex(7, 8));

    // Adding more nodes for depth
    auto node2 = tree.root->children[0];
    tree.add_sub_node(node2, Complex(9, 10));
    tree.add_sub_node(node2, Complex(11, 12));
    tree.add_sub_node(node2, Complex(13, 14));

    // Use the BFSIterator on a K-ary complex tree
    std::ostringstream oss;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        oss << (*it)->value << " ";
    }

   
    CHECK(oss.str() == "1 + 2i 3 + 4i 5 + 6i 7 + 8i 9 + 10i 11 + 12i 13 + 14i ");
}

TEST_CASE("Test DFSIterator on a K-ary complex tree (K = 3)") {
    Tree<Complex, 3> tree; // K-ary complex tree (K = 3)
    tree.add_root(Complex(1, 2));
   
    tree.add_sub_node(tree.root, Complex(3, 4));
    tree.add_sub_node(tree.root, Complex(5, 6));
    tree.add_sub_node(tree.root, Complex(7, 8));

    // Adding more nodes for depth
    auto node2 = tree.root->children[0];
    tree.add_sub_node(node2, Complex(9, 10));
    tree.add_sub_node(node2, Complex(11, 12));
    tree.add_sub_node(node2, Complex(13, 14));

    // Use the DFSIterator on a K-ary complex tree
    std::ostringstream oss;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        oss << (*it)->value << " ";
    }

   
    CHECK(oss.str() == "1 + 2i 3 + 4i 9 + 10i 11 + 12i 13 + 14i 5 + 6i 7 + 8i ");
}



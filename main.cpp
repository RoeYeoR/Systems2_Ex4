#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include "designwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    designWindow window; // Create your main window



    std::cout << std::endl;
    std::cout <<"Actions on binary tree !" <<std::endl;
    std::cout << std::endl;

    Tree<Complex> tree;

    tree.add_root(Complex(1.1, 2.2));
    auto n1 = std::make_shared<Node<Complex>>(Complex(1.2, 2.3));
    auto n2 = std::make_shared<Node<Complex>>(Complex(1.3, 2.4));
    auto n3 = std::make_shared<Node<Complex>>(Complex(1.4, 2.5));
    auto n4 = std::make_shared<Node<Complex>>(Complex(1.5, 2.6));
    auto n5 = std::make_shared<Node<Complex>>(Complex(1.6, 2.7));

    tree.add_sub_node(tree.root, Complex(1.2, 2.3));
    tree.add_sub_node(tree.root, Complex(1.3, 2.4));
    tree.add_sub_node(tree.root->children[0], Complex(1.4, 2.5));
    tree.add_sub_node(tree.root->children[0], Complex(1.5, 2.6));
    tree.add_sub_node(tree.root->children[1], Complex(1.6, 2.7));

    // Pre-Order Traversal
    std::cout << "Pre-Order Traversal: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // BFS Traversal
    std::cout << "BFS Traversal: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS Traversal
    std::cout << "DFS Traversal: ";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Post-Order Traversal
    std::cout << "Post-Order Traversal: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // In-Order Traversal (not fully implemented for non-binary trees, demonstration only)
    std::cout << "In-Order Traversal: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Adding more nodes
    auto n6 = std::make_shared<Node<Complex>>(Complex(1.7, 2.8));
    auto n7 = std::make_shared<Node<Complex>>(Complex(1.8, 2.9));
    auto n8 = std::make_shared<Node<Complex>>(Complex(1.9, 3.0));
    auto n9 = std::make_shared<Node<Complex>>(Complex(2.0, 3.1));

    tree.add_sub_node(tree.root->children[0]->children[0], Complex(1.7, 2.8));
    tree.add_sub_node(tree.root->children[0]->children[0], Complex(1.8, 2.9));
    tree.add_sub_node(tree.root->children[1]->children[0], Complex(1.9, 3.0));
    tree.add_sub_node(tree.root->children[1]->children[0], Complex(2.0, 3.1));

    // Pre-Order Traversal after adding more nodes
    std::cout << "Pre-Order Traversal after adding more nodes: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // BFS Traversal after adding more nodes
    std::cout << "BFS Traversal after adding more nodes: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS Traversal after adding more nodes
    std::cout << "DFS Traversal after adding more nodes: ";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Post-Order Traversal after adding more nodes
    std::cout << "Post-Order Traversal after adding more nodes: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // In-Order Traversal after adding more nodes (not fully implemented for non-binary trees, demonstration only)
    std::cout << "In-Order Traversal after adding more nodes: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Transform to min-heap
    tree.myHeap();

    // Pre-Order Traversal after heap transformation
    std::cout << "Pre-Order Traversal after heap transformation: ";
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // BFS Traversal after heap transformation
    std::cout << "BFS Traversal after heap transformation: ";
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS Traversal after heap transformation
    std::cout << "DFS Traversal after heap transformation: ";
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Post-Order Traversal after heap transformation
    std::cout << "Post-Order Traversal after heap transformation: ";
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // In-Order Traversal after heap transformation (not fully implemented for non-binary trees, demonstration only)
    std::cout << "In-Order Traversal after heap transformation: ";
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout <<"Actions on 5-ary tree !" <<std::endl;
    std::cout << std::endl;

    Tree<Complex, 5> tree2;
    tree2.add_root(Complex(10.0, 2.0));
    tree2.add_sub_node(tree2.root, Complex(5.0, 2.1));
    tree2.add_sub_node(tree2.root, Complex(6.0, 2.2));
    tree2.add_sub_node(tree2.root, Complex(7.0, 2.3));
    tree2.add_sub_node(tree2.root, Complex(8.0, 2.4));
    tree2.add_sub_node(tree2.root, Complex(9.0, 2.5));
    tree2.add_sub_node(tree2.root->children[0], Complex(1.0, 2.6));
    tree2.add_sub_node(tree2.root->children[0], Complex(2.0, 2.7));
    tree2.add_sub_node(tree2.root->children[0], Complex(3.0, 2.8));
    tree2.add_sub_node(tree2.root->children[0], Complex(4.0, 2.9));

    // BFS Traversal
    std::cout << "BFS Traversal after adding more nodes: ";
    for (auto it = tree2.begin_bfs_scan(); it != tree2.end_bfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // DFS Traversal
    std::cout << "DFS Traversal after adding more nodes: ";
    for (auto it = tree2.begin_dfs_scan(); it != tree2.end_dfs_scan(); ++it) {
        std::cout << (*it)->get_value() << " ";
    }
    std::cout << std::endl;

    // Print tree to GUI
    tree.printTree(mainWindow);

    // Show the main window
    mainWindow.show();

    return app.exec();

    return 0;
}

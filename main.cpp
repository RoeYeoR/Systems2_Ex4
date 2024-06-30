#include <iostream>
#include "tree.hpp"
#include "complex.hpp"

int main() {
    // Creating a Tree of Complex Numbers
    std::cout << "Creating Tree of Complex Numbers:\n";
    Tree<Complex> complexTree;

    complexTree.add_root(Complex(1.0, 2.0));
    auto root = complexTree.root;
    complexTree.add_sub_node(root, Complex(3.0, 4.0));
    auto node3 = root->children[0];
    complexTree.add_sub_node(root, Complex(5.0, 6.0));
    complexTree.add_sub_node(node3, Complex(7.0, 8.0));

    // Using Pre-Order Iterator for Complex Tree
    std::cout << "Pre-Order Traversal of Complex Tree:\n";
    for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
        std::cout << (*it)->value << " ";
    }
    std::cout << std::endl;

    // Using In-Order Iterator for Complex Tree
    std::cout << "In-Order Traversal of Complex Tree:\n";
    for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
        std::cout << (*it)->value << " ";
    }
    std::cout << std::endl;

    // // Using Post-Order Iterator for Complex Tree
    // std::cout << "Post-Order Traversal of Complex Tree:\n";
    // for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
    //     std::cout << (*it)->value << " ";
    // }
    // std::cout << std::endl;

    return 0;
}

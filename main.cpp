#include <iostream>
#include "tree.hpp"
#include "complex.hpp"

int main() {

     std::cout << std::endl;
    std::cout << "Creating a Binary Tree ... \n";
    Tree<int> binaryTree;
   
    binaryTree.add_root(5);
    Node<int>* root = binaryTree.root;

    binaryTree.add_sub_node(root,7);
    binaryTree.add_sub_node(root,2);

    Node<int>* left_Node = root->children[0];
    Node<int>* right_Node = root->children[1];

    
    binaryTree.add_sub_node(left_Node,3);
    binaryTree.add_sub_node(left_Node,4);
  
    Node<int>* left_left_Node = left_Node->children[0];
    Node<int>* right_left_Node = left_Node->children[1];

    std::cout << std::endl;
    std::cout << "Pre-Order traversal:"<<std::endl;
    for(auto it = binaryTree.begin_pre_order(); it != binaryTree.end_pre_order(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    } 
    
    std::cout << std::endl;
    std::cout << "In-Order traversal:"<<std::endl;
    for(auto it = binaryTree.begin_in_order(); it != binaryTree.end_in_order(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    }


    std::cout << std::endl;
    std::cout << "Post-Order traversal:"<<std::endl;
    for(auto it = binaryTree.begin_post_order(); it != binaryTree.end_post_order(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    }


    binaryTree.myHeap();

    std::cout << std::endl;
    std::cout << "Post-Order traversal after myHeap():"<<std::endl;
    for(auto it = binaryTree.begin_post_order(); it != binaryTree.end_post_order(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    }

    std::cout << std::endl;
    std::cout << "Creating a K-ary Tree (K=3 for this example) ... "<<std::endl;

    Tree<double,3> tree2;

    tree2.add_root(3.14);
    Node<double>* root2 = tree2.root;

    tree2.add_sub_node(root2,2.16);
    tree2.add_sub_node(root2,6.37);
    tree2.add_sub_node(root2,4.76);

    Node<double>* leftNode_root2 = root2->children[0];
    Node<double>* middleNode_root2= root2 ->children[1];
    Node<double>* rightNode_root2= root2 ->children[2];

    tree2.add_sub_node(leftNode_root2,1.12);
    tree2.add_sub_node(leftNode_root2,9.22);
    tree2.add_sub_node(leftNode_root2,7.45);

    tree2.add_sub_node(middleNode_root2,8.24);

    tree2.add_sub_node(rightNode_root2,4.32);

    std::cout << std::endl;
    std::cout << "BFS-Scan:"<<std::endl;
    for(auto it = tree2.begin_bfs_scan(); it != tree2.end_bfs_scan(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    }

    std::cout << std::endl;
    std::cout << "DFS-Scan:"<<std::endl;
    for(auto it = tree2.begin_dfs_scan(); it != tree2.end_dfs_scan(); ++it)
    {
        std::cout << (*it)->get_value() << "\n";
    }



    //Binary Tree of Complex Numbers
    std::cout << std::endl;
    std::cout << "Creating a Binary Tree of Complex Numbers ...\n";

    Tree<Complex> complexTree;

    complexTree.add_root(Complex(5, 6));
    Node<Complex>* root3 = complexTree.root;

    complexTree.add_sub_node(root3, Complex(3, 4));
    complexTree.add_sub_node(root3, Complex(1, 2));

    Node<Complex>* leftNode_root3 = root3->children[0];
    Node<Complex>* rightNode_root3 = root3->children[1];

    complexTree.add_sub_node(rightNode_root3, Complex(7, 8));

    
    std::cout << "Pre-Order Traversal of Complex Tree:\n" << std::endl;
    for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
        std::cout << (*it)->value << "\n";
    }
    std::cout << std::endl;

   
    std::cout << "In-Order Traversal of Complex Tree:\n";
    for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
        std::cout << (*it)->value << "\n";
    }
    std::cout << std::endl;

   
    std::cout << "Post-Order Traversal of Complex Tree:\n";
    for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
        std::cout << (*it)->value << "\n";
    }
    std::cout << std::endl;

    //complexTree.myHeap();

    // std::cout << "In-Order Traversal after myHeap():\n";
    // for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
    //     std::cout << (*it)->value << "\n";
    // }
    // std::cout << std::endl;

   // complexTree.printInOrder();

    return 0;
}

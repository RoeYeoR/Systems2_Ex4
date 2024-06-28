#include <QApplication>
#include "mainwindow.hpp"
#include "node.hpp"
#include "tree.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    Tree<double> tree;
    tree.add_root(1.1);
    auto n1 = std::make_shared<Node<double>>(1.2);
    auto n2 = std::make_shared<Node<double>>(1.3);
    auto n3 = std::make_shared<Node<double>>(1.4);
    auto n4 = std::make_shared<Node<double>>(1.5);
    auto n5 = std::make_shared<Node<double>>(1.6);

    tree.add_sub_node(tree.root, 1.2);
    tree.add_sub_node(tree.root, 1.3);
    tree.add_sub_node(tree.root->children[0], 1.4);
    tree.add_sub_node(tree.root->children[0], 1.5);
    tree.add_sub_node(tree.root->children[1], 1.6);

    // Display the tree structure
    tree.printTree(window);

    window.show();
    return app.exec();
}

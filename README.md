## Tree Data Structure with Tree Traversal and Complex Numbers

This project implements a generic tree data structure (`Tree`) in C++ with support for various traversal methods and includes a `Complex` number class for demonstration purposes.

## Files Included

- **`tree.hpp`**: Defines the `Tree` class template that supports operations for creating, modifying, and traversing a generic tree structure. It includes iterators for Pre-Order, In-Order, Post-Order, BFS (Breadth-First Search), and DFS (Depth-First Search) traversals.

- **`node.hpp`**: Contains the `Node` class template used by `tree.hpp` to represent nodes within the tree structure. Each node stores a value of type `T` and maintains a vector of child nodes.

- **`complex.hpp`**: Implements a `Complex` number class with basic arithmetic operations and comparison operators. It also includes an overloaded stream insertion operator (`<<`) for convenient output.

- **`main.cpp`**: Demonstrates the usage of the `Tree` class with various types (`int`, `double`, and `Complex`). It creates instances of trees, adds nodes, performs traversals using different iterators, and showcases the use of the `Complex` class within the tree structure.

- **`test.cpp`**: Contains unit tests using the `doctest` framework to validate the functionality of tree traversal iterators (`PreOrderIterator`, `InOrderIterator`, `PostOrderIterator`, `BFSIterator`, `DFSIterator`) on both binary and K-ary trees, including transformations like `myHeap()` on binary trees and operations with `Complex` numbers.

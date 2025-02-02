//315144972
//roeyshmil09@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node<T>*> children;

    Node(T val) : value(val) {}

    T get_value() const {
        return value;
    }

    void add_child(Node<T>* child) {
        children.push_back(child);
    }

     void clear_children() {
        children.clear();
    }
};

#endif // NODE_HPP

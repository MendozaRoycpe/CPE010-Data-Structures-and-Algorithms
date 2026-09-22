//
// Created by royga on 9/19/2026.
//

#ifndef UNTITLED1_GENTREE_H
#define UNTITLED1_GENTREE_H

#include <iostream>

// General tree using linked lists as the internal representation:
//   firCld -> this node's first child (head of its child list)
//   nxtSib -> the next node in that same child list (this node's next sibling)
template <typename T>
class genTree {
private:
    T key;                 // value stored in this node
    genTree<T>* firCld;    // pointer to the first child (nullptr if none)
    genTree<T>* nxtSib;    // pointer to the next sibling (nullptr if none)

    // Private search helpers, overloaded against the public traversal
    // functions of the same name below (same name, different parameters).
    // Each one walks the tree in its own visiting order and returns true
    // as soon as value is found, without printing anything.
    bool preOrder(T value);
    bool postOrder(T value);
    bool inOrder(T value);

public:
    // Constructor: builds a new node holding value, with no children or siblings yet
    genTree(T value);

    // Destructor: deletes this node's whole child list, then every sibling after it,
    // so calling delete on the root frees the entire tree
    ~genTree();

    // Adds a new child at the END of this node's child list, returns a pointer to it
    genTree<T>* insert(T value);

    // Searches this node and all of its descendants (pre-order). Returns nullptr if not found
    genTree<T>* find(T value);

    // Traversing algorithms: each one prints every key to the console
    void preOrder();
    void postOrder();
    void inOrder();

    // Prints the tree, one node per line, indented by depth (level)
    void printTree(int depth = 0);

    // CHOICE: 1 = pre-order, 2 = post-order, 3 = in-order
    // Searches using the chosen order and prints "[KEY]was found!" if found,
    // otherwise prints nothing
    void findData(int choice, T value);
};

// Constructor: stores the value and marks this node as a fresh leaf
template <typename T>
genTree<T>::genTree(T value) {
    key = value;
    firCld = nullptr;   // no children yet
    nxtSib = nullptr;   // no next sibling yet
}

// Destructor: recursively deletes the child list and the sibling chain.
// delete on a nullptr is safe and does nothing, so leaves and last
// siblings stop the recursion naturally.
template <typename T>
genTree<T>::~genTree() {
    delete firCld;   // destroys this node's entire subtree of children
    delete nxtSib;   // destroys every sibling that comes after this node
}

// Adds value as a new child of this node
template <typename T>
genTree<T>* genTree<T>::insert(T value) {
    genTree<T>* node = new genTree<T>(value);   // create the new child node

    if (firCld == nullptr) {
        // This node has no children yet, so the new node becomes the first child
        firCld = node;
    } else {
        // Walk to the end of the existing child list...
        genTree<T>* current = firCld;
        while (current->nxtSib != nullptr) {
            current = current->nxtSib;
        }
        // ...then attach the new node after the last sibling
        current->nxtSib = node;
    }
    return node;   // caller can keep this pointer to add grandchildren later
}

// Depth-first (pre-order style) search: checks this node, then each child's subtree
template <typename T>
genTree<T>* genTree<T>::find(T value) {
    if (key == value) {
        return this;   // found at this node
    }
    // Check every child in turn (firCld starts the list, nxtSib advances through it)
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        genTree<T>* result = child->find(value);
        if (result != nullptr) {
            return result;   // found somewhere in this child's subtree
        }
    }
    return nullptr;   // not found anywhere in this subtree
}

// Pre-order: Root -> each child (left to right)
template <typename T>
void genTree<T>::preOrder() {
    std::cout << key << " ";   // visit (print) the root first
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->preOrder();     // then recurse into every child, left to right
    }
}

// Post-order: each child (left to right) -> Root
template <typename T>
void genTree<T>::postOrder() {
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->postOrder();    // visit every child's subtree first
    }
    std::cout << key << " ";   // print the root only after all children are done
}

// In-order (general tree convention): first child's subtree -> Root -> remaining children's subtrees.
// A node with no children is simply printed.
template <typename T>
void genTree<T>::inOrder() {
    if (firCld == nullptr) {
        std::cout << key << " ";   // leaf: nothing to visit before or after
        return;
    }
    firCld->inOrder();             // visit the first child's subtree
    std::cout << key << " ";       // then print this node, in between
    // then visit the remaining children, starting from the second child
    for (genTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        child->inOrder();
    }
}

// Prints the tree top to bottom, indenting each node by its depth
template <typename T>
void genTree<T>::printTree(int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "    ";       // 4 spaces per level of depth
    }
    std::cout << key << "\n";      // print this node on its own line
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        child->printTree(depth + 1);   // children are one level deeper
    }
}

// Pre-order search: Root -> each child. Stops and returns true as soon as value is found
template <typename T>
bool genTree<T>::preOrder(T value) {
    if (key == value) {
        return true;
    }
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->preOrder(value)) {
            return true;
        }
    }
    return false;
}

// Post-order search: each child -> Root. This node's own key is checked last
template <typename T>
bool genTree<T>::postOrder(T value) {
    for (genTree<T>* child = firCld; child != nullptr; child = child->nxtSib) {
        if (child->postOrder(value)) {
            return true;
        }
    }
    return key == value;   // checked only after every child has been checked
}

// In-order search: first child's subtree -> Root -> remaining children's subtrees
template <typename T>
bool genTree<T>::inOrder(T value) {
    if (firCld == nullptr) {
        return key == value;       // leaf: only this node to check
    }
    if (firCld->inOrder(value)) {
        return true;               // found in the first child's subtree
    }
    if (key == value) {
        return true;               // found at this node
    }
    for (genTree<T>* child = firCld->nxtSib; child != nullptr; child = child->nxtSib) {
        if (child->inOrder(value)) {
            return true;           // found in one of the remaining children
        }
    }
    return false;
}

// Uses the traversal chosen by CHOICE (1 = pre, 2 = post, 3 = in) to search
// for value. Prints "[value]was found!" only when the search succeeds.
template <typename T>
void genTree<T>::findData(int choice, T value) {
    bool found = false;

    switch (choice) {
        case 1: found = preOrder(value);  break;   // calls the private bool preOrder(T)
        case 2: found = postOrder(value); break;   // calls the private bool postOrder(T)
        case 3: found = inOrder(value);   break;   // calls the private bool inOrder(T)
        default:
            return;   // invalid choice: no output at all
    }

    if (found) {
        std::cout << "[" << value << "]was found!" << "\n";
    }
    // found == false: no output, as required
}

#endif //UNTITLED1_GENTREE_H
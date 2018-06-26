#pragma GCC optimize("O2")
#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <string>

enum Color { RED,
    BLACK }; // (true, false)

// ===================== Node ======================

struct Node {
    int key, height, weight;
    std::string gender;
    bool color;
    Node *left = nullptr, *right = nullptr, *p = nullptr;
    // Constructor
    Node(int key, const std::string gender, int height, int weight)
        : key(key)
        , gender(gender)
        , height(height)
        , weight(weight)
    {
        ;
    }
    inline const std::string& getGender() const { return gender; }
    inline const int& getHeight() const { return height; }
    inline const int& getWeight() const { return weight; }
};

// ===================== RBT =======================

class RBTree {
private:
    Node* root;
    inline void left_rotate(Node*& x)
    {
        Node* y = x->right;
        if (x->p == nullptr)
            root = y;
        else {
            if (x == x->p->left)
                x->p->left = y;
            else
                x->p->right = y;
        }
        y->p = x->p;
        x->right = y->left;
        y->left->p = x;
        y->left = x;
        x->p = y;
    }
    inline void right_rotate(Node*& x)
    {
        Node* y = x->left;
        if (x->p == nullptr)
            root = y;
        else {
            if (x->p->left == x)
                x->p->left = y;
            else
                x->p->right = y;
        }
        y->p = x->p;
        x->left = y->right;
        y->right->p = x;
        y->right = x;
        x->p = y;
    }
    // This function fixes violations caused by BST insertion
    inline void fix_violation(Node*& x)
    {
        Node* p_ptr = nullptr;
        Node* grand_p_ptr = nullptr;

        while ((x != root) && (x->color != BLACK)
            && (x->p->color == RED)) {
            p_ptr = x->p;
            grand_p_ptr = x->p->p;

            //  Case A:
            //  p at grandp's left

            if (p_ptr == grand_p_ptr->left) {
                Node* uncle_ptr = grand_p_ptr->right;

                //  Case 1:
                //  uncle is also RED

                if (uncle_ptr != nullptr && uncle_ptr->color == RED) {
                    grand_p_ptr->color = RED;
                    p_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    x = grand_p_ptr;
                }

                else {

                    // Case 2:
                    // x is right child of its p
                    // Left-rotation required

                    if (x == p_ptr->right) {
                        left_rotate(p_ptr);
                        x = p_ptr;
                        p_ptr = grand_p_ptr;
                    }

                    // Case 3:
                    // x is left child of its p
                    // Right-rotation required

                    right_rotate(grand_p_ptr);
                    std::swap(p_ptr->color, grand_p_ptr->color);
                    x = p_ptr;
                }
            }

            // Case B:
            // p at grandp's right

            else {
                Node* uncle_ptr = grand_p_ptr->left;

                // Case 1:
                // uncle also RED

                if ((uncle_ptr != nullptr) && (uncle_ptr->color == RED)) {
                    grand_p_ptr->color = RED;
                    p_ptr->color = BLACK;
                    uncle_ptr->color = BLACK;
                    x = grand_p_ptr;
                }

                else {

                    // Case 2:
                    // x at p's Left

                    if (x == p_ptr->left) {
                        right_rotate(p_ptr);
                        x = p_ptr;
                        p_ptr = x->p;
                    }

                    // Case 3:
                    // x at p's x_right

                    left_rotate(grand_p_ptr);
                    std::swap(p_ptr->color, grand_p_ptr->color);
                    x = p_ptr;
                }
            }
        }
        root->color = BLACK;
    }

public:
    // Constructor
    RBTree() { root = nullptr; }
    // BSTree insertion
    inline bool insert(int key, const std::string gender, int height, int weight)
    {
        try {
            Node* t = new Node(key, gender, height, weight);
            Node* x = root;
            Node* y = nullptr;
            while (x != nullptr) {
                y = x;
                if (key == x->key)
                    return false;
                else if (key < x->key)
                    x = x->left;
                else
                    x = x->right;
            }
            t->p = y;
            if (y == nullptr)
                root = t;
            else {
                if (key == y->key)
                    return false;
                else if (t->key < y->key)
                    y->left = t;
                else
                    y->right = t;
            }
            t->left = nullptr;
            t->right = nullptr;
            t->color = true;
            fix_violation(t);
            return true;
        } catch (...) {
            return false;
        }
    }
    //  operator []
    inline Node& operator[](int key)
    {
        Node* x = root;
        while (x->key != key && x != nullptr) {
            if (x->key > key)
                x = x->left;
            else
                x = x->right;
        }
        return *x;
    }
    inline const Node operator[](int key) const
    {
        Node* x = root;
        while (x->key != key && x != nullptr) {
            if (x->key > key)
                x = x->left;
            else
                x = x->right;
        }
        return *x;
    }
};

#endif

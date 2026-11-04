#ifndef TREE_H
#define TREE_H
#include <iostream>

struct Node {
    char data;
    Node* firstChild;
    Node* nextSibling;

    Node(char value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};
// Add a child to a parent node
void addChild(Node* parent, Node* child) {
    if (parent->firstChild == nullptr) {
        parent->firstChild = child;
    }
    else {
        Node* temp = parent->firstChild;

        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }

        temp->nextSibling = child;
    }
}
// Display the tree
void displayTree(Node* root, int level = 0) {
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }

    std::cout << root->data << std::endl;

    Node* child = root->firstChild;

    while (child != nullptr) {
        displayTree(child, level + 1);
        child = child->nextSibling;
    }
}

// FOR ILO B
// Pre-order
void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";

    Node* child = root->firstChild;

    while (child != nullptr) {
        preOrder(child);
        child = child->nextSibling;
    }
}

// Post-order
void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {
        postOrder(child);
        child = child->nextSibling;
    }

    std::cout << root->data << " ";
}

// In-order
void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    Node* child = root->firstChild;

    if (child != nullptr) {
        inOrder(child);

        std::cout << root->data << " ";

        child = child->nextSibling;

        while (child != nullptr) {
            inOrder(child);
            child = child->nextSibling;
        }
    }
    else {
        std::cout << root->data << " ";
    }
}

//TASK 3.3 & 3.4
bool found;
// Search Pre-order
void searchPreOrder(Node* root, char key) {
    if (root == nullptr || found) {
        return;
    }

    if (root->data == key) {
        found = true;
        return;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {
        searchPreOrder(child, key);
        child = child->nextSibling;
    }
}

// Search Post-order
void searchPostOrder(Node* root, char key) {
    if (root == nullptr || found) {
        return;
    }

    Node* child = root->firstChild;

    while (child != nullptr) {
        searchPostOrder(child, key);
        child = child->nextSibling;
    }

    if (root->data == key) {
        found = true;
    }
}

// Search In-order
void searchInOrder(Node* root, char key) {
    if (root == nullptr || found) {
        return;
    }

    Node* child = root->firstChild;

    if (child != nullptr) {
        searchInOrder(child, key);

        if (root->data == key) {
            found = true;
            return;
        }

        child = child->nextSibling;

        while (child != nullptr && !found) {
            searchInOrder(child, key);
            child = child->nextSibling;
        }
    }
    else {
        if (root->data == key) {
            found = true;
        }
    }
}

void findData(Node* root, int choice, char key) {
    found = false;

    if (choice == 1) {
        searchPreOrder(root, key);
    }
    else if (choice == 2) {
        searchPostOrder(root, key);
    }
    else if (choice == 3) {
        searchInOrder(root, key);
    }

    if (found) {
        std::cout << key << " was found!" << std::endl;
    }
}



#endif
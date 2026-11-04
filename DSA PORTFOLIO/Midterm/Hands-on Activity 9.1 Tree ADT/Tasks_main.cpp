#include <iostream>
#include "tree.h"

int main() {

    // Create the nodes
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');
    Node* G = new Node('G');
    Node* H = new Node('H');
    Node* I = new Node('I');
    Node* J = new Node('J');
    Node* K = new Node('K');
    Node* L = new Node('L');
    Node* M = new Node('M');
    Node* N = new Node('N');
    Node* P = new Node('P');
    Node* Q = new Node('Q');

    // Connect the nodes
    addChild(A, B);
    addChild(A, C);
    addChild(A, D);
    addChild(A, E);
    addChild(A, F);
    addChild(A, G);

    addChild(D, H);

    addChild(E, I);
    addChild(E, J);

    addChild(J, P);
    addChild(J, Q);

    addChild(F, K);
    addChild(F, L);
    addChild(F, M);

    addChild(G, N);

    // Display the tree
    std::cout << "Tree:" << std::endl;
    displayTree(A);

    // Traversals
    std::cout << "\nPre-order: ";
    preOrder(A);
    std::cout << std::endl;

    std::cout << "Post-order: ";
    postOrder(A);
    std::cout << std::endl;

    std::cout << "In-order: ";
    inOrder(A);
    std::cout << std::endl;
    
    std::cout << "\nFind Data:" << std::endl;
    findData(A, 1, 'J');  // Pre-order
    findData(A, 2, 'P');  // Post-order
    findData(A, 3, 'G');  // In-order

    Node* O = new Node('O');
    addChild(G, O);

    // Test findData after adding O
    std::cout << "\nAfter adding O:" << std::endl;

    findData(A, 1, 'O');
    findData(A, 2, 'O');
    findData(A, 3, 'O');

    return 0;
}
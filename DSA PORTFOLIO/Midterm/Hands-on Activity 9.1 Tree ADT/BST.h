#ifndef BST_H
#define BST_H


template <typename T>
class BinarySearchTree{
    private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;
    public:
    //constructor:
    BinarySearchTree(T value);
    // insertion:
    void insert(T value);
    
    // TRAVERSAL:
    void preOrder();
    void inOrder();
    void postOrder();

};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    left = nullptr;
    right = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert (T value){
    // go to left if: value < key
    if(value < key){

        if(left == nullptr){
            left = new BinarySearchTree<T>(value);
        }else{
            left->insert(value);
        }
    }
    else if(value > key){
        if (right == nullptr){
            right = new BinarySearchTree<T>(value);
        }else{
            right->insert(value);
        }
    }
}
// ============= PRE-ORDER ================
template<typename T>
void BinarySearchTree<T>::preOrder(){
    std::cout<< key << " ";
    if(left != nullptr){
        left->preOrder();
    }
    if(right != nullptr){
        right->preOrder();
    }
}
// ============= IN-ORDER ================
template<typename T>
void BinarySearchTree<T>::inOrder(){

    if(left != nullptr){
        left->preOrder();
    }
     std::cout<< key << " ";

    if(right != nullptr){
        right->preOrder();
    }
}
// ============= POST-ORDER ================
template<typename T>
void BinarySearchTree<T>::postOrder(){

    if(left != nullptr){
        left->postOrder();
    }
    if(right != nullptr){
        right->postOrder();
    }
    
     std::cout<< key << " ";
}

#endif
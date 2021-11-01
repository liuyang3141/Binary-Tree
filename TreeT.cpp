
#include "TreeT.h"

template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {
    DestroyTree(root);
}

template<class T>
TreeT<T> &TreeT<T>::operator=(const TreeT &otherTree) {
    if (this == &otherTree)
        return *this;

    CopyHelper(this->root, &otherTree->root);

    return *this;
}

template<class T>
void TreeT<T>::Add(T value) {
    /* Iterative implementation
    Node* curr = root;

    while (curr != nullptr) {
        if (curr-> value == value)
            return;
        else if (value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    curr = new Node;
    curr->value = value;
    ++numNodes;*/
}

template<class T>
void TreeT<T>::Remove(T value) {
    RemoveHelper(root, value);
}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value) {
    // this function searches for where the value is in the tree
    // if it's not on the right or the left, then we've found it, then call DeleteNode()
    if (value < subtree->value)
        RemoveHelper(subtree->left, value);
    else if (value > subtree->value)
        RemoveHelper(subtree->right, value);
    else
        DeleteNode(subtree);
}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node *&subtree) {
    T data;
    Node* tempPtr;
    tempPtr = subtree;

    if (subtree->left == nullptr && subtree->right == nullptr)  {
        delete subtree;
        subtree == nullptr;
    }
    else if (subtree->left == nullptr)  {
        subtree = subtree->right;
        delete tempPtr;
    }
    else if (subtree->right == nullptr) {
        subtree = subtree->left;
        delete tempPtr;
    }
    else    {
        GetPredecessor(subtree->left, data);
        subtree->info = data;
        RemoveHelper(subtree->left, data);
    }
}

template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T &value) {
    while (curr->right != nullptr)
        curr = curr->right;

    value = curr->value;
}

template<class T>
bool TreeT<T>::Contains(T value) {
    return ContainsHelper(root, value);

    /* Iterative implementation
    Node *curr = root;

    while (curr != nullptr) {
        if (curr->value == value)
            return true;
        else if (value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // If root is null or value not found in while loop, then jump here.
    return false;
    */
}

template<class T>
bool TreeT<T>::ContainsHelper(TreeT::Node *subroot, T value) {
    if (subroot == nullptr)
        return false;

    else if (subroot->value == value)
        return true;

    else if (value < subroot->value)
        return ContainsHelper(subroot->left, value);

    else
        return ContainsHelper(subroot->right, value);

}

template<class T>
int TreeT<T>::Size() {
    return numNodes;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {
    iterArr.empty();
    if (traverseOrder == 0) {
        PlacePostOrder(root);
    }
    else if (traverseOrder == 1)    {
        PlaceInOrder(root);
    }
    else
        PlacePreOrder(root);

}

template<class T>
T TreeT<T>::GetNextItem() {
    return nullptr;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
}

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree) {
    thisTree->value = otherTree->value;
    CopyHelper(thisTree->left, otherTree->left);
    CopyHelper(thisTree->right, otherTree->right);
}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {
    if (node == nullptr)
        return;

    iterArr.push(node->value);
    PlacePreOrder(node->left);
    PlacePreOrder(node->right);
}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {
    if (node == nullptr)
        return;

    PlacePostOrder(node->left);
    PlacePostOrder(node->right);
    iterArr.push(node->value);
}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {
    if (node == nullptr)
        return;

    PlaceInOrder(node->left);
    iterArr.push(node->value);
    PlaceInOrder(node->right);
}



template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {

}

template<class T>
TreeT &TreeT<T>::operator=(const TreeT &otherTree) {
    return;
}

template<class T>
void TreeT<T>::Add(T value) {

    Node* curr = root;
    Node* parent = nullptr;

    while(curr != nullptr)  {
        if (value == curr->value)
            return;

        if (value < curr->value)
            curr = curr->left;

        else
            curr = curr->right;

        parent = curr;
    }
    Node* newNode = new Node;

    if(parent == nullptr)   {
        root = newNode; // if the first node is empty
    }
    if (value < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    ++numNodes;
    curr->value = value;
}

template<class T>
void TreeT<T>::Remove(T value) {

}

template<class T>
bool TreeT<T>::Contains(T value) {
    Node* curr = new Node;
    curr = root;

    while(curr != nullptr)  {
        if (value == curr->value)
            return true;

        if (value < curr->value)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return false;
}

template<class T>
int TreeT<T>::Size() {
    return 0;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {

}

template<class T>
T TreeT<T>::GetNextItem() {
    return nullptr;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value) {

}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node *&subtree) {

}

template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T &value) {

}

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree) {

}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {

}

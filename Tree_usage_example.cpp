//
// Created by we7289 on 2/18/2021.
//

#include <iostream>
#include "TreeT.h"
#include <queue>

int main(void) {

    TreeT<int> treeA;
    treeA.Add(10);
    treeA.Add(2);

    TreeT<int> treeB;

    treeB = treeA;

    treeB.ResetIterator(IN_ORDER);
    for (int i = 0; i < treeB.Size(); i++) {
        cout << treeB.GetNextItem() << " ";
    }
    cout << endl;

    TreeT<int>* tree = new TreeT<int>;

    tree->Add(5);
    tree->Add(1);
    tree->Add(10);
    tree->Add(2);

    tree->ResetIterator(IN_ORDER);
    for (int i = 0; i < tree->Size(); i++) {
        cout << tree->GetNextItem() << " ";
    }
    cout << endl;

    delete tree;

    return 0;
}
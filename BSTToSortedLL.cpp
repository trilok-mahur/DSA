#include<bits/stdc++.h>
using namespace std;
#include "student.cpp"

long int MODULO = 1000000007;

int main() {
    Binary_tree *root = NULL;
    root = insert_data_in_BST(root);
    cout << endl;

    printBinaryTreeLevelWise(root);

    int k;
    cout <<"\nEnter the data = ";
    cin >> k;
    vector<int> *output = getpath_in_BT(root, k);
    int n = output->size();
    reverse(output->begin(), output->end());
    if (output != NULL) {
        for (int i = 0; i < n; i++) {
            cout << output->at(i) << " ";
        }
    }

    cout << endl;

    cout <<"Given tree is BST = " << isBST(root);
    delete root;

}

// thisIsCamelCasing
// this_is_snake_casing
// TO_NAME_CONSTANTS
// MULTI_WORD_CONSTANT
 
#include<bits/stdc++.h>
using namespace std;
class treeNode{
    public :
    int data;
    vector<treeNode *>  child;
    treeNode(int data) {
        this->data = data;
    }
};
bool areIdentical(treeNode *root1, treeNode * root2) {
    if(root1 == NULL && root2 == NULL ) {
        return true;
    }
    if(root1 == NULL && root2 != NULL) {
        return false;
    }
    if(root1 != NULL && root2 == NULL) {
        return false;
    }
    int m = root1->child.size();
    if( root1->child.size() != root2->child.size()) {
        return false;
    }
    if(root1->data != root2->data) {
        return false;
    }
    bool ans = true;
    for(int i = 0; i < m; i++) {
        ans = areIdentical(root1->child[i], root2->child[i]);
    }

    return ans;
}
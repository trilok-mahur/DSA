#include<bits/stdc++.h>
using namespace std;
class treeNode{
    public :
    int data;
    vector<treeNode *> children;
    treeNode(int data) {
        this->data = data;
    }
};
void replaceWithDepthValueHelper(treeNode * root, int depth) {
    if (root == NULL) {
        return;
    }
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++) {
      replaceWithDepthValueHelper(root->children[i], depth + 1);
    }
    return;
}
void replaceWithDepthValue(treeNode * root) {
   return replaceWithDepthValueHelper(root, 0);
}
int main() {

}
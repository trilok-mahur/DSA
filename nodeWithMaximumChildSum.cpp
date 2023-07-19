#include<bits/stdc++.h>
using namespace std;
class treeNode{
    public :
    int data;
    vector<treeNode *>  child;
    treeNode(int data) {
        this->data = data;
    }
    treeNode() {

    }
};

class pairt{
    public :
    int max;
    treeNode* Node;
};
pairt* helper(treeNode* root) {
    if(root == NULL) {
        pairt* output = new pairt();
        output->max = INT_MIN;
        output->Node = NULL;
        return output;
    }
    int sum  = root->data;
    for(int i = 0; i < root->child.size(); i++) {
        sum += root->child[i]->data;
    }
    pairt *ans = new pairt();
    ans->Node = root;
    ans->max = sum;
    for(int i = 0; i < root->child.size(); i++) {
        pairt * child = helper(root->child[i]);
        if(ans->max < child->max) {
            ans = child;
        }
    }
    return ans;
    
}
treeNode* maxSumNode(treeNode* root) {
    return helper(root)->Node;
} 

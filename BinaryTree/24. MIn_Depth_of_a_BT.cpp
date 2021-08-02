//Minimum depth of the binary tree

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
int minDepth(Node* root){
    if(!root){
        return 0;
    }
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if(lh == 0){
        return 1 + rh;
    }
    if(rh == 0){
        return 1 + lh;
    }
    return 1 + min(lh, rh);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    minDepth(root);
    
    return 0;
}
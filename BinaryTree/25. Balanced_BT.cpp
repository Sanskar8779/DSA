//Check if the given BT is height balanced or not

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
int height(Node* root){
    if(!root){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if((lh == -1) || (rh == -1) || (abs(lh - rh) > 1)){
        return -1;
    }
    return 1 + max(lh, rh);
}
bool isBalanced(Node *root){
    if(height(root) == -1){
        return false;
    }
    return true;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(isBalanced(root)){
        cout << "The Binary tree is height balanced" << endl;
    }
    else{
        cout << "The binary tree is not height balanced" << endl;
    }
    
    return 0;
}
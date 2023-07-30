//

#include <bits/stdc++.h>  
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};

int height(Node *root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(Node *root){
    return height(root) != -1;
}

int main(){
    Node* root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->left =new Node(4);
    root->left->right =new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    bool ans = isBalanced(root);
    if(ans){
        cout << "Yes the tree is height balanced" << endl;
    }else{
        cout << "No the tree is not height balanced" << endl;
    }
    return 0;
}

//Time C :- O(N)
//Space C :- O(N)
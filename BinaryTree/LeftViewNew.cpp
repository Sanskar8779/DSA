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

void LeftView(Node *root, int level, vector<int> &res){
    if(!root) return;
    //We have to do preorder traversal
    //VLR traversal
    if(level == res.size()) res.push_back(root->data);
    
    LeftView(root->left, level + 1, res);
    LeftView(root->right, level + 1, res);
}

int main(){
    Node* root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->left =new Node(4);
    root->left->right =new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    vector<int> res;
    LeftView(root, 0, res);
    for(auto it:res){
        cout << it << " ";
    }
    return 0;
}
//Level order Traversal using recursion

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
int height(Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
void Levelorder(Node *root, int level){
    if(root == 0){
        return;
    }
    if(level == 0){
        cout<<root->data<<" ";
        return;
    }
    if(root->left != NULL){
        Levelorder(root->left, level-1);
    }
    if(root->right != NULL){
        Levelorder(root->right, level-1);
    }
}
int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int h = height(root);
    for(int i = 0; i <= h; i++){
        Levelorder(root, i);
    }
    return 0;
}

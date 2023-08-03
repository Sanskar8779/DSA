//

#include <bits/stdc++.h>  
using namespace std;
class Node{
public:
   int data;
   Node* left;
   Node* right;
   Node(int key){
       data = key;
       left = NULL;
       right = NULL;
   }
};

Node* LowestCommonAncestor(Node*root, Node*p, Node*q){
    //base case
    if(root == NULL || root == p || root == q){
        return root;
    }
    Node *left = LowestCommonAncestor(root->left, p, q);
    Node *right = LowestCommonAncestor(root->right, p, q);
    //result
    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{//both left and right are not null return root
        return root;
    }
    //TC :- O(N)
    //SC :- O(N)
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    Node *var = LowestCommonAncestor(root, root->right->right, root->right->right->right);
    cout << var->data << endl;
    return 0;
}
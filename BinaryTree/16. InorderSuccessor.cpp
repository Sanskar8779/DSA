// Inorder Successor of a Node
#include<bits/stdc++.h>
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
 
void InorderSuccessor(Node* root, Node* target_node, Node* &next)
{ 
    if(root == NULL){
        return;
    }
 
    InorderSuccessor(root->right, target_node, next);

    if(root->data == target_node->data)
    {
        if(next == NULL){
            cout << "Inorder successor of "<< root->data << " is: Null"<<endl;
        }
        else{
            cout << "Inorder successor of "<< root->data << " is: "<< next->data <<endl;
        }
    }

    next = root;
    InorderSuccessor(root->left, target_node, next);
}
 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->right = new Node(9);
    root->left->right->left = new Node(8);
     
    Node* next = NULL;
    InorderSuccessor(root, root->right, next);
 
    next = NULL;
    InorderSuccessor(root, root->left->left, next);
 
    next = NULL;
    InorderSuccessor(root, root->right->right, next);

    next = NULL;
    InorderSuccessor(root, root->left->right, next);

    next = NULL;
    InorderSuccessor(root, root->left->right->right, next);
     
    return 0;
}
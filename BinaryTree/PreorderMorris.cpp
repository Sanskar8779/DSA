//Preorder Without recursion or stack(Morris Traversal)

#include <bits/stdc++.h>  
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
void MorrisPreorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            Node *pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = curr;
                cout<<curr->data<<" ";
                curr = curr->left;
            }else{
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    MorrisPreorder(root);
    return 0;
}
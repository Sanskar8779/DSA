//Inorder Without recursion or stack(Morris Traversal)
//           1
//         /  \
//        2    3
//       / \   / \
//      4  5  6   7

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
void MorrisInorder(Node *root){
    if(root == NULL){
        return;
    }
    Node *curr = root;
    Node *pre;
    while(curr!=NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else if(pre->right == curr){
                pre->right = NULL;
                cout<<curr->data<<" ";
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
 
    MorrisInorder(root);
    
    return 0;
}

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
void ZigZagLevelOrder(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(s1.empty() != true || s2.empty() != true){
        while(s1.empty()!=true){
            Node *temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                s2.push(temp->left);
            }
            if(temp->right != NULL){
                s2.push(temp->right);
            }
        }
        while(s2.empty() != true){
            Node *temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right != NULL){
                s1.push(temp->right);
            }
            if(temp->left != NULL){
                s1.push(temp->left);
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
    ZigZagLevelOrder(root);
    return 0;
}
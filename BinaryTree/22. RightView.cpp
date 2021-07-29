//Right view of a binary tree

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
void RightView(Node *root){
    if(!root){
        return;
    }
    queue<Node *>q;
    q.push(root);
    while(q.empty() != true){
        int size = q.size();
        Node *curr = q.back();
        cout << curr->data << " ";
        while(size > 0){
            Node *temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            size--;
        }
    }


}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    RightView(root);
    
    return 0;
}
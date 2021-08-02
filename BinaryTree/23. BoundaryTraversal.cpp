//Boundary traversal of the binary tree

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
void BoundaryTraversal(Node* root){
    if(!root){
        return;
    }
    vector<int> vec_left;
    vec_left.push_back(root->data);
    Node *curr = root->left;
    while(curr->left){
        vec_left.push_back(curr->data);
        curr = curr->left;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(!(temp->left) && !(temp->right)){
            vec_left.push_back(temp->data);
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    vector<int> vec_right;
    Node *pre = root->right;
    while(pre->right){
        vec_right.push_back(pre->data);
        pre = pre->right;
    }
    reverse(vec_right.begin(),vec_right.end());
    vec_left.insert(vec_left.end(), vec_right.begin(), vec_right.end());
    for(auto it:vec_left){
        cout << it << " ";
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
    BoundaryTraversal(root);
    
    return 0;
}
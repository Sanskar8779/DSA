//Reverse level order traversal in binary tree

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
void ReverseLevelOrder(Node *root){
    if(!root){
        return;
    }
    vector<int> vec;
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false){
        Node* temp = q.front();
        vec.push_back(temp->data);
        q.pop();
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }

    }
    for(auto it = vec.rbegin(); it != vec.rend(); it++){
        cout << *it << " ";
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
    ReverseLevelOrder(root);
    
    return 0;
}
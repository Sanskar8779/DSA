// Width of a binary tree
// it is the maximum of the number of nodes of all the levels
// For Ex- level 1 has only 1 node 
// level 2 can have maximum of 2 nodes 
// so width = max(nodes(level 1), nodes(level 2)) =max(1, 2) = 2
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
 
int width(Node *root){
    if(root == NULL){
        return 0;
    }
    queue<Node *> q;
    int res = 0;
    q.push(root);
    while(q.empty() != true){
        int nodeCount = q.size();
        res = max(res, nodeCount);
        if(nodeCount == 0){
            break;
        }
        while(nodeCount > 0){
            Node *temp = q.front();
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            nodeCount--;
        }
        
    }
    return res;
}
 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    int w = width(root);
    cout<<"The width of this binary tree is "<<w<<" ."<<endl;
    
     
    return 0;
}
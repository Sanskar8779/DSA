//Level Order Traversal Line by Line

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
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
void LevelOrderLinebyLine(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(true){
        int nodeCount = q.size();
        if(nodeCount == 0){
            break;
        }
        while(nodeCount > 0){
            Node *temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
            nodeCount--;
        }
        cout<<endl;
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
    LevelOrderLinebyLine(root);
    return 0;
}
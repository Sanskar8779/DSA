//Vertical width of a binary tree

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
void lengthUtil(Node* root, int &maximum, int &minimum, int curr=0)
{
    if (root == NULL){
        return;
    }
    
    lengthUtil(root->left, maximum, minimum, curr - 1);
    
    if (minimum > curr){
        minimum = curr;
    }
  
    if (maximum < curr){
        maximum = curr;
    }
  
    lengthUtil(root->right, maximum, minimum,  curr + 1);
  
}
  
int getLength(Node* root)
{
    int maximum = 0, minimum = 0;
    lengthUtil(root, maximum, minimum, 0);
  
    return (abs(minimum) + maximum) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << getLength(root) << "\n";
    return 0;
}
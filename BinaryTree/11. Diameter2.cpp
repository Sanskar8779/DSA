//Diameter of Binary tree
//Time complexity of this program is O(n)
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};
 
int height(Node *root, int &diameter){
    if(!root) return 0;
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh+rh);
    return 1 + max(lh, rh);
}

int diameter(Node *root){
    if(!root) return 0;
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
 
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->left->left = new Node(9);
    root->right->left->right = new Node(10);
    root->right->left->right->right = new Node(11);
        
    cout<<"Diameter: "<<diameter(root);
    
    return 0;
}
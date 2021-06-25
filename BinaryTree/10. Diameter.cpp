//Diameter of a Binary tree
//Time complexity of this program is O(n^2)
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
 
int height(Node* node)
{
    if (node == NULL)
        return 0;
 
    return 1 + max(height(node->left), height(node->right));
}

 
int diameter(Node* tree)
{
    if(tree == NULL){
        return 0;
    }
    int lh = height(tree->left);
    int rh = height(tree->right);
    int ldia = diameter(tree->left);
    int rdia = diameter(tree->right);
    return max(1 + lh + rh, max(ldia, rdia));
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
    
    cout << "Diameter of the given binary tree is " <<diameter(root)<<endl;
    return 0;
}
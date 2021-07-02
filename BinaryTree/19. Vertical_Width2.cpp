//Vertical width of a binary tree different approach

//           1
//         /  \
//        2    3
//       / \   / \
//      4  5  6   7
//                 \
//                  8

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data, hd;
    Node *left, *right;
    Node(int key){
        data = key;
        left = right = NULL;
    }
};

class Value{
public:
    int min,max;
};

void findminmax(Node *root, Value *minimum, Value *maximum, int hd){
    if(root == NULL){
        return;
    }
    if(minimum->min > hd){
        minimum->min = hd;
    }
    else if(maximum->max < hd){
        maximum->max = hd;
    }
    findminmax(root->left, minimum, maximum, hd-1);
    findminmax(root->right, minimum, maximum, hd+1);
}
int verticalwidth(Node * root){
    Value *val = new Value();
    findminmax(root, val, val, 0);
    return abs(val->max - val->min) + 1;
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    int v = verticalwidth(root);
    cout<<"The vertical width of the binary tree is "<<v<<endl;
    return 0;
}
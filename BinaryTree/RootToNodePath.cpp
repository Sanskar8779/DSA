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

bool getPath(Node *root, vector<int> &vec, int x){
    if(!root) return false;
    vec.push_back(root->data);
    if(root->data == x) return true;
    if(getPath(root->left, vec, x) || getPath(root->right, vec, x)){
        return true;
    }
    vec.pop_back();
    return false;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    vector<int> ans;
    bool sol = getPath(root, ans, 8);
    if(sol){
        for(auto it:ans){
            cout << it << " ";
        }
    }
    return 0;
}
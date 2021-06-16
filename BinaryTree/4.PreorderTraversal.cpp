//Preorder with recursion

#include <bits/stdc++.h>
using namespace std;
class Tree{
public:
   int key;
   Tree* left;
   Tree* right;
   Tree(int k){
      key = k;
      left = NULL;
      right = NULL;
   }
};

void preorder(Tree *root){
   if(root == NULL){
      return;
   }else{
      cout<<root->key<<" ";
      preorder(root->left);
      preorder(root->right);
   }
}

int main(){
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    preorder(root);
    cout<<endl;
    return 0;
}

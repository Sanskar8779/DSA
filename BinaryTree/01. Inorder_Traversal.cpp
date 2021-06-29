//Inorder with recursion
//           1
//         /  \
//        2    3
//       / \   / \
//      4  5  6   7

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

void inorder(Tree *root){
   if(root == NULL){
      return;
   }else{
      inorder(root->left);
      cout<<root->key<<" ";
      inorder(root->right);
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
    inorder(root);

    return 0;
}

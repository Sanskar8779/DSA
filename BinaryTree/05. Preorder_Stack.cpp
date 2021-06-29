//Preorder Traversal without recursion and using stack

//           1
//         /  \
//        2    3
//       / \   / \
//      4  5  6   7

#include <bits/stdc++.h>
#include <stack>
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
void Preorder(Node* root){
    stack<Node*> st;
    Node* curr = root;
    if(root == NULL){
        return;
    }
    while(curr!=NULL || st.empty() != true){
        while(curr!=NULL){
            st.push(curr);
            cout<<curr->data<<" ";
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        curr = curr->right;
    }    
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Preorder(root);
    return 0;
}

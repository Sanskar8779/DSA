//Postorder Traversal withot recursion and using stack

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
void postorder(Node *root){
    stack<Node*>st;
    Node *curr = root;
    if(root == NULL){
        return;
    }
    while(true){
        while(curr!=NULL){
            st.push(curr);
            st.push(curr);
            curr = curr->left;
        }
        if(st.empty() == true){
            return;
        }
        curr = st.top();
        st.pop();
        if(st.empty() != true && curr == st.top()){
            curr = curr->right;
        }else{
            cout<<curr->data<<" ";
            curr = NULL;
        }
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
    postorder(root);
    return 0;
}
//

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

int maxPath(Node* root, int &maxi){
    if(!root) return 0;
    int leftSum = max(0, maxPath(root->left, maxi));
    int rightSum = max(0, maxPath(root->right, maxi));
    maxi = max(maxi, root->data + leftSum + rightSum);
    return root->data + max(leftSum, rightSum);
}

int maxPathSum (Node* root){
    int maxi = INT_MIN;
    maxPath(root, maxi);
    return maxi;
}


int main(){
    Node* root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(33);
    root->left->left =new Node(4);
    root->left->right =new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int ans = maxPathSum(root);
    cout << "The maximum path sum gives sum as " << ans << endl;
    

    return 0;
}
//Deepest leaves sum  leetcode
//the idea is to return the sum of the last level in the bianry tree

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
int deepestLeavesSum(Node* root){
    if(!root){
        return 0;
    }
    int sum = 0;
    queue<Node*> q;
    q.push(root);
    while(true){
        int nodeCount = q.size();
        if(nodeCount == 0){
            break;
        }
        sum = 0;
        while(nodeCount > 0){
            Node* temp = q.front();
            q.pop();
            sum += temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            nodeCount--;
        }
    }
    return sum;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int result = deepestLeavesSum(root);
    cout << "The required answer is " << result << endl;
    
    return 0;
}
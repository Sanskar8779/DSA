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

void ZigZag(Node *root, vector<vector<int>> &vec){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while(q.empty() != true){
        int size = q.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            Node *node = q.front();
            q.pop();

            int index = (leftToRight) ? i : (size - i - 1);
            row[index] = node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        vec.push_back(row);
    }
}

int main(){
    Node* root = new Node(1);
    root->left =new Node(2);
    root->right = new Node(3);
    root->left->left =new Node(4);
    root->left->right =new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<vector<int>> vec;
    ZigZag(root, vec);
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

//Time C :- O(N)
//Space C :- O(N)
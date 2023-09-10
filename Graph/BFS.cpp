//

#include <bits/stdc++.h>  
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it:adj[node]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }

    //Space Complexity :- O(3N) ~ O(N)
    //Time complexity :- O(N) + O(2E)
    //O(N) is for while loop
    //O(2E) is for for loop which is running for the total degree of the nodes

int main(){
    int n = 5;
    int m = 4;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = bfsOfGraph(n, adj);
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}
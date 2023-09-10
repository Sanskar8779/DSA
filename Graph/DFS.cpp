//

#include <bits/stdc++.h>  
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &vec){
        vis[node] = 1;
        vec.push_back(node);
        for(auto it:adj[node]){
            if(vis[it] == 0){
                dfs(it, adj, vis, vec);
            }
        }
    }

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> vec;
        dfs(start, adj, vis, vec);
        return vec;
    }
//SC :- O(N)
//TC :- O(N) + O(2E)
int main(){
    int n = 5;
    int m = 4;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = dfsOfGraph(n, adj);
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}
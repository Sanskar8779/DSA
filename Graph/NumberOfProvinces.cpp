//

#include <bits/stdc++.h>  
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it] == 0){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                count++;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};
//Space complexity :- O(N) + O(N){For stack space worst case in the case of skewed graph}
//Time complexity :- O(N) + O(V + 2E) ~ O(N)

int main(){
    Solution ob;
    vector<vector<int>> adj
    {
        {1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1}
    };

    int ans = ob.findCircleNum(adj);
    cout << ans << endl;
    return 0;
}
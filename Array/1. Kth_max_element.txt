// Problem no. 215 Leetcode
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it:nums){
            pq.push(it);
        }
        int ans = 0;
        int size = pq.size();
        int count = 1;
        while(size){
            if(count == k){
                ans = pq.top();
                return ans;
            }
            count++;
            pq.pop();
            size--;
        }
        return -1;
    }
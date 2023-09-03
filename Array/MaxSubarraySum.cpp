//Kadane's Algorithm
//

#include <bits/stdc++.h>  
using namespace std;

int Kadane(vector<int> &nums){
    int maxi = INT_MIN;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        maxi = max(maxi, sum);
        if(sum < 0) sum=0;
    }
    return maxi;
}

int main(){
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = Kadane(vec);
    cout << "Max subarray sum is " << ans << endl;
    return 0;
}
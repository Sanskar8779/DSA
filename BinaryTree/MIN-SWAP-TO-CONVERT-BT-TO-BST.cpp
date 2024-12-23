#include <bits/stdc++.h>
using namespace std;
int minSwap(vector<int> &nums, int n) {
	int ans = 0;
	vector<pair<int, int>> vec;
	for(int i=0; i<n; i++) {
		vec.push_back({nums[i],  i});
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<n; i++) {
		if(vec[i].second == i) continue;
		else{
			ans++;
			swap(vec[i], vec[vec[i].second]);
			i--;
		}
	}
	return ans;
}
void inorderTraversal(vector<int>&nums, vector<int>&inorder, int index) {
	int n = nums.size();
	if(index >= n) return;
	inorderTraversal(nums, inorder, 2*index + 1);
	inorder.push_back(nums[index]);
	inorderTraversal(nums, inorder, 2*index + 2);
}
int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.
	vector<int> inorder;
	inorderTraversal(arr, inorder, 0);
	int ans = minSwap(inorder, n);
	return ans;
}

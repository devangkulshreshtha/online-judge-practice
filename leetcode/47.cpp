#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

vector<vector<int>> get_permutations(vector<int> nums, vector<bool> considered) {

	vector<vector<int>> ans;
	int i,j;

	rep(i, nums.size()) if(considered[i]==true) {
		rep(j, i) if(nums[i]==nums[j] and considered[j] == true) break;
		if(j!=i) continue;
		considered[i] = false;
		vector<vector<int>> child_ans = get_permutations(nums, considered);
		rep(j, child_ans.size()) {
			child_ans[j].pb(nums[i]);
			ans.pb(child_ans[j]);
		}
		if(child_ans.size()==0) {
			vector<int> temp;
			temp.pb(nums[i]);
			ans.pb(temp);
		}
		considered[i] = true;
	}

	return ans;

}

vector<vector<int>> permuteUnique(vector<int>& nums) {

	vector<bool> considered(nums.size(), true);
	return get_permutations(nums, considered);

}

int main()  
{

	vector<int> nums = {1,1,2};
	vector<vector<int>> ans = permuteUnique(nums);
	for(auto v : ans) {
		for(auto x : v) cout << x << " ";
		cout << "\n";
	}
	return 0;
}


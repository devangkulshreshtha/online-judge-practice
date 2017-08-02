#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

vector<vector<int>> get_combinations(set<int> nums, int k) {

	vector<vector<int>> ans;
	int i,j;
	if(k==0) return ans;

	for(auto it = nums.begin(); it != nums.end(); ++it) {
		set<int> nums_removed = nums;
		nums_removed.erase(*it);
		vector<vector<int>> child_ans = get_combinations(nums_removed, k-1);
		rep(j, child_ans.size()) {
			child_ans[j].pb(*it);
			ans.pb(child_ans[j]);
		}
		if(child_ans.size()==0) {
			vector<int> temp;
			temp.pb(*it);
			ans.pb(temp);
		}
	}

	return ans;

}

vector<vector<int>> combine(int n, int k) {
	
	vector<vector<int>> ans;
	if(k==0 or n<k) return ans;
	vector<vector<int>> ans1 = combine(n-1, k-1);
	vector<vector<int>> ans2 = combine(n-1, k);
	for(auto v : ans1) {
		v.pb(n);
		ans.pb(v);
	}
	for(auto v : ans2) 
		ans.pb(v);
	if(ans1.size()==0) {
		vector<int> temp;
		temp.pb(n);
		ans.pb(temp);
	}

	return ans;

}

int main()  
{

	vector<vector<int>> ans = combine(4, 2);
	for(auto v : ans) {
		for(auto x : v) cout << x << " ";
		cout << "\n";
	}
	return 0;
}


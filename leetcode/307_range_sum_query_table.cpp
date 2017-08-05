#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

class NumArray {
public:

	vector<int> tree;
	int n;

	NumArray(vector<int> nums) {

	    int i;
	    n = nums.size();

	    rep(i,n)
	    	tree.pb(0);
	    for(i=n;i<2*n;i++) 
	    	tree.pb(nums[i-n]);
	    //rep(i, 2*n) cout << tree[i] << " ";
	    for(i=n-1;i>0;i--)
	    	tree[i] = tree[i<<1] + tree[i<<1 | 1];

	    //rep(i, 2*n) cout << tree[i] << " ";

	}

	void update(int i, int val) {

		tree[n+i] = val;
	    for(int p=n+i;p>1;p>>=1)
	    	tree[p>>1] = tree[p] + tree[p^1];

	}

	int sumRange(int i, int j) {

	    int res = 0, l, r;
	    for(l=i+n,r=j+n; l<r; l>>=1,r>>=1) {
	    	if(l&1) res += tree[l++];
	    	if(r&1) res += tree[--r];
	    }
	    return res;

	}

};

int main()  
{

	vector<int> nums = {1,3,5};
	NumArray numArray = NumArray(nums);
	cout << numArray.sumRange(0, 3) << " ";
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 3) << " ";

	return 0;
}


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

int arrayNesting(vector<int>& nums) {
	
	vector<int> parent(nums.size(), -1);
	int i, n = nums.size();
	rep(i, n) {
		int j=i;
		while(parent[j]==-1) {
			parent[j] = i;
			j = nums[j];
		}
	}
	
	map<int, int> frequencyMap;
    int maxFrequency = 0;
    int mostFrequentElement = 0;
    for (int x : parent)
    {
        int f = ++frequencyMap[x];
        if (f > maxFrequency)
        {
            maxFrequency = f;
            mostFrequentElement = x;
        }
    }

    return maxFrequency;

}

int main()  
{
	
	vector<int> arr = {5,4,0,3,1,6,2};
	cout << arrayNesting(arr);

	return 0;
}


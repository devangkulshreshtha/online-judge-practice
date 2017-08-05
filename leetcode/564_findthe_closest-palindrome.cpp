
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

int cmp(string s1, string s2) {
	return s1.compare(s2);
}

string add(string s1, string s2) {

	int n=s1.length(), i, carry=0;
	string ans = "";
	for(i=n-1;i>=0;i--) {
		int output = (s1[i]-'0') + (s2[i]-'0') + carry;
		ans += output%10 + '0';
		carry = output/10 + '0';
	}
	ans += carry + '0';

	reverse(ans.begin(), ans.end());
	return ans;
}

string nearestPalindromic(string n) {

	string minPalindrome1 = n, minPalindrome2 = n;
	int i, l=n.size();

	for(i=0;i<l/2;i++)
		minPalindrome1[l-1-i] = n[i], minPalindrome2[l-i-1] = n[i];
	if(n[(l-1)/2]!='0')
		minPalindrome1[(l-1)/2] = minPalindrome1[l/2] = n[(l-1)/2] - 1;

	//cout << minPalindrome1 << " " << minPalindrome2 << "\n";

	if(cmp(add(n,n) , add(minPalindrome1,minPalindrome2)) < 0 or minPalindrome2==n)
		return minPalindrome1;
	else
		return minPalindrome2;
        
}

int main()  
{
	
	string ans = "1";
	cout << nearestPalindromic(ans);

	return 0;
}


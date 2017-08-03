#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

string serialize(TreeNode* root) {

    string data = "";
    if(root==NULL)
    	return data;

    data = to_string(root->val);
    string left = serialize(root->left);
    string right = serialize(root->right);
    if(left!="")
    	data += "-" + left;
    if(right!="")
    	data += "-" + right;

    return data;

}

TreeNode* deserialize(string data) {

	if(data=="")
		return NULL;
	//cout << data << " ";

	vector<int> BSTData;
	int i,j;
	string token;
	stringstream ss(data);
	while(getline(ss, token, '-')) {
		BSTData.pb(stoi(token));
	}

	TreeNode* root;
	if(BSTData.size()==0)
		return NULL;

	root = new TreeNode(BSTData[0]);
	//cout << BSTData[2] << "\n";
	for(i=1;i<BSTData.size();i++) 
		if(BSTData[i] > root->val)
			break;

	//cout << i << "\n";

	string left="", right="";
	for(j=1;j<i;j++)
		left += to_string(BSTData[j]) + "-";
	for(j=i;j<BSTData.size();j++)
		right += to_string(BSTData[j]) + "-";


	if(left.size()!=0) 
		left = left.substr(0, left.length()-1);
	
	if(right.size()!=0) 
		right = right.substr(0, right.length()-1);


	TreeNode *left_ans = deserialize(left);
	TreeNode *right_ans = deserialize(right);
	root->left = left_ans;
	root->right = right_ans;

	return root;
}

int main()  
{

	// string checker = "10-4-14";
	// TreeNode *ans = deserialize(checker);
	// cout << ans->val << " " << ans->left->val << ans->right->val;
	
	TreeNode *root = new TreeNode(10);
	TreeNode *left = new TreeNode(4);
	TreeNode *right = new TreeNode(14);
	root->left = left;
	root->right = right;
	cout << serialize(root);

	return 0;
}


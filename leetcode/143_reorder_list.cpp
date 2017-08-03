#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(i=0;i<n;i++) 
#define pb push_back

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {

	if(head==NULL or head->next==NULL) return ;

	ListNode* tail = head, *prev;
	while(tail->next!=NULL) {
		prev = tail;
		tail = tail->next;
	}

	prev->next = NULL;
	reorderList(head->next);
	tail->next = head->next;
	head->next = tail;

    return ;

}

int main()  
{

	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	reorderList(head);
	while(head!=NULL) {
		cout << head->val << " ";	
		head = head->next;
	}

	return 0;
}


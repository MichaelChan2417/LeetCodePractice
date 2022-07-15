#pragma once
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	void init(vector<int>& ll) {
		val = ll[0];
		ListNode* temp = new ListNode();
		next = temp;
		for (int i = 1; i < ll.size(); i++) {
			temp->val = ll[i];
			if (i != ll.size() - 1) {
				ListNode* newnode = new ListNode();
				temp->next = newnode;
				temp = temp->next;
			}
		}
	}
	ListNode() : val(),next() {}
	ListNode(int x) : val(x), next(nullptr) {}

	
};



void PrintSingleList(ListNode* l) {
	while (l != NULL) {
		cout << l->val << "->";
		l = l->next;
	}
	cout << endl;
}

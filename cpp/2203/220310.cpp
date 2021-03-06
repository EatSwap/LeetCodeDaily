#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode* next;

	explicit ListNode(int x = 0, ListNode* next = nullptr) : val(x), next(next) {}
};

/**
 * 2. Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

class Solution {
public:
	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1 || !l2)
			return l1 ? l1 : l2;

		int cin = (l1->val + l2->val) / 10;
		ListNode* ret = new ListNode((l1->val + l2->val) % 10);
		ListNode* ptr = ret;

		for (ListNode* ptr1 = l1->next, * ptr2 = l2->next; ptr1 || ptr2; ) {
			int cur = cin + (ptr1 ? l1->val : 0) + (ptr2 ? l2->val : 0);
			ptr = ptr->next = new ListNode(cur % 10, nullptr);
			cin = cur / 10;
			ptr1 = ptr1 ? ptr1->next : nullptr;
			ptr2 = ptr2 ? ptr2->next : nullptr;
		}

		if (cin)
			ptr->next = new ListNode(cin, nullptr);
		return ret;
	}
};

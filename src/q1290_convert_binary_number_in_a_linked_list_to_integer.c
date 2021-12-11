#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int _getDecimalValue(struct ListNode* head) {
	int values[30];
	int len = 0;
	int result = 0;
	struct ListNode *h = head;
	while (h != NULL) {
		values[len++] = h->val;
		h = h->next;
	}
	for (int i = len - 1; i >= 0; i--) {
		result += values[i] << (len - 1 - i);
	}
	return result;
}

int getDecimalValue(struct ListNode* head) {
	int rst = 0;
	while (head != NULL) {
		rst <<= 1;
		rst += head->val;
		head = head->next;
	}
	return rst;
}

int main() {
	{
		struct ListNode hd = {.val = 1};
		struct ListNode n2 = {.val = 0};
		struct ListNode n3 = {.val = 1};
		hd.next = &n2;
		n2.next = &n3;
		printf("e1: %d\n", getDecimalValue(&hd));
	}

	{
		struct ListNode hd = {.val = 0};
		printf("e1: %d\n", getDecimalValue(&hd));
	}

	{
		struct ListNode hd = {.val = 1};
		printf("e1: %d\n", getDecimalValue(&hd));
	}

	{
		struct ListNode hd = {.val = 1};
		struct ListNode n2 = {.val = 0};
		struct ListNode n3 = {.val = 0};
		struct ListNode n4 = {.val = 1};
		struct ListNode n5 = {.val = 0};
		struct ListNode n6 = {.val = 0};
		struct ListNode n7 = {.val = 1};
		struct ListNode n8 = {.val = 1};
		struct ListNode n9 = {.val = 1};
		struct ListNode n10 = {.val = 0};
		struct ListNode n11 = {.val = 0};
		struct ListNode n12 = {.val = 0};
		struct ListNode n13 = {.val = 0};
		struct ListNode n14 = {.val = 0};
		struct ListNode n15 = {.val = 0};
		hd.next = &n2;
		n2.next = &n3;
		n3.next = &n4;
		n4.next = &n5;
		n5.next = &n6;
		n6.next = &n7;
		n7.next = &n8;
		n8.next = &n9;
		n9.next = &n10;
		n10.next = &n11;
		n11.next = &n12;
		n12.next = &n13;
		n13.next = &n14;
		n14.next = &n15;
		printf("e1: %d\n", getDecimalValue(&hd));
	}

	{
		struct ListNode hd = {.val = 0};
		struct ListNode n2 = {.val = 0};
		hd.next = &n2;
		printf("e1: %d\n", getDecimalValue(&hd));
	}

	return 0;
}


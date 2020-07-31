#include "../solution/add_two_numbers.h"

void add_two_numbers_test() {
  ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  ListNode *result = AddTwoNumbers::addTwoNumbers(l1, l2);

  ListNode *head = result;
  cout << head->val << endl;
  while (head->next) {
    head = head->next;
    cout << head->val << endl;
  }

}

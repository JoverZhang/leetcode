#include <leetcode_utils/utils.h>

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  explicit ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumbers {
 public:
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int sum = 0;
    ListNode *l3 = nullptr;
    ListNode **node = &l3;
    while (l1 != nullptr || l2 != nullptr || sum > 0) {
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      (*node) = new ListNode(sum % 10);
      sum /= 10;
      node = &((*node)->next);
    }
    return l3;
  }
};

int main() {
  auto *l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  auto *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  auto *result = AddTwoNumbers::addTwoNumbers(l1, l2);

  auto *head = result;
  cout << head->val << endl;
  while (head->next) {
    head = head->next;
    cout << head->val << endl;
  }

  return 0;
}

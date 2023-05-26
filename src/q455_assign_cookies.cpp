#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int n = 0;

    while (i < g.size() && j < s.size()) {
      if (g[i] <= s[j]) {
        n++;
        i++;
        j++;
      } else {
        j++;
      }
    }

    return n;
  }
};

TEST(Q455_ASSIGN_COOKIES, 1) {
  {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    ASSERT_EQ(1, Solution{}.findContentChildren(g, s));
  }
  {
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    ASSERT_EQ(2, Solution{}.findContentChildren(g, s));
  }
  {
    vector<int> g = {10, 9, 8, 7};
    vector<int> s = {5, 6, 7, 8};
    ASSERT_EQ(2, Solution{}.findContentChildren(g, s));
  }
}
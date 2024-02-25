#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int32_t> map(128, 0);
    for (auto c : t) {
      ++map[c];
    }

    auto counter = static_cast<int32_t>(t.size());
    int32_t i = 0;
    int32_t j = 0;
    int32_t start = 0;
    int32_t len = INT_MAX;

    while (j < s.size()) {
      if (map[s[j++]]-- > 0) {
        --counter;
      }

      while (counter == 0) {
        if (map[s[i]]++ == 0) {
          if (j - i < len) {
            len = j - (start = i);
          }
          ++counter;
        }
        i++;
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};

TEST(Q76_MINIMUM_WINDOW_SUBSTRING, 1) {
  ASSERT_EQ("BANC", Solution{}.minWindow("ADOBECODEBANC", "ABC"));
  ASSERT_EQ("a", Solution{}.minWindow("a", "a"));
  ASSERT_EQ("", Solution{}.minWindow("a", "aa"));
}
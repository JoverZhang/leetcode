#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

#include <cstddef>
#include <cstdint>

class Solution {
 public:
#if 0
  int longestCommonSubsequence(string text1, string text2) {
    vector<std::int32_t> dp((text1.size() + 1) * (text2.size() + 1), 0);
    auto lcs = [&](uint32_t i, uint32_t j) -> int32_t& {
      return dp[i * (text2.size() + 1) + j];
    };

    for (size_t i = 1; i <= text1.size(); ++i) {
      for (size_t j = 1; j <= text2.size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          lcs(i, j) = lcs(i - 1, j - 1) + 1;
        } else {
          lcs(i, j) = max(lcs(i - 1, j), lcs(i, j - 1));
        }
      }
    }

    return lcs(text1.size(), text2.size());
  }
#else
  int longestCommonSubsequence(string text1, string text2) {
    vector<int32_t> prev(text2.size() + 1, 0);
    vector<int32_t> curr(text2.size() + 1, 0);

    for (size_t i = 1; i <= text1.size(); ++i) {
      for (size_t j = 1; j <= text2.size(); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          curr[j] = prev[j - 1] + 1;
        } else {
          curr[j] = max(curr[j - 1], prev[j]);
        }
      }
      prev = curr;
    }

    return curr[text2.size()];
  }
#endif
};

TEST(Q1143_LONGEST_COMMON_SUBSEQUENCE, 1) {
  ASSERT_EQ(3, Solution{}.longestCommonSubsequence("abcde", "ace"));
  ASSERT_EQ(2, Solution{}.longestCommonSubsequence("ezupkr", "ubmrapg"));
  ASSERT_EQ(1, Solution{}.longestCommonSubsequence("bsbininm", "jmjkbkjkv"));
}
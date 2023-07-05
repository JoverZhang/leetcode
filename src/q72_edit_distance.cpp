#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

class Solution {
public:
  int minDistance(string word1, string word2) {
    auto dp =
        vector<vector<int>>(word1.size() + 1, vector<int>(word2.size() + 1));
    dp[0][0] = 0;

    for (int i = 0; i <= word1.size(); ++i)
      dp[i][0] = i;
    for (int i = 0; i <= word2.size(); ++i)
      dp[0][i] = i;

    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        }
      }
    }

    return dp[word1.size()][word2.size()];
  }
};

//     r o s
//   0 1 2 3
// h 1 1 2 3
// o 2 2 1
// r 3
// s 4
// e 5

TEST(Q72_EDIT_DISTANCE, 1) {
  Solution s;
  EXPECT_EQ(s.minDistance("horse", "ros"), 3);
  EXPECT_EQ(s.minDistance("intention", "execution"), 5);
  EXPECT_EQ(s.minDistance("pneumonoultramicroscopicsilicovolcanoconiosis",
                          "ultramicroscopically"),
            27);
}

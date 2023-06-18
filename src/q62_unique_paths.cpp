#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    auto dp = vector<vector<int>>(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
      dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};

TEST(Q62_UNIQUE_PATHS, 1) {
  {
    ASSERT_EQ(28, Solution{}.uniquePaths(3, 7));
  }
  {
    ASSERT_EQ(3, Solution{}.uniquePaths(3, 2));
  }
}
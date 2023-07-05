#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

class Solution {
 public:
#if 0
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    auto m = static_cast<int>(dungeon.size());
    auto n = static_cast<int>(dungeon[0].size());

    auto dp = vector<vector<int>>(m, vector<int>(n, 0));

    dp[m - 1][n - 1] = min(dungeon[m - 1][n - 1], 0);

    for (int i = m - 2; i >= 0; i--) {
      dp[i][n - 1] = min(dp[i + 1][n - 1] + dungeon[i][n - 1], 0);
    }
    for (int i = n - 2; i >= 0; i--) {
      dp[m - 1][i] = min(dp[m - 1][i + 1] + dungeon[m - 1][i], 0);
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = min(max(dp[i + 1][j], dp[i][j + 1]) + dungeon[i][j], 0);
      }
    }

    return max(-dp[0][0], 0) + 1;
  }
#else
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    auto m = static_cast<int>(dungeon.size());
    auto n = static_cast<int>(dungeon[0].size());

    auto dp = vector<vector<int>>(m, vector<int>(n, 0));
    dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

    for (int i = m - 2; i >= 0; i--) {
      dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      dp[m - 1][i] = max(1, dp[m - 1][i + 1] - dungeon[m - 1][i]);
    }

    for (int i = m - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
#endif
};

TEST(Q174_DUNGEON_GAME, 1) {
  {
    auto dungeon = vector<vector<int>>{
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5},
    };
    ASSERT_EQ(7, Solution().calculateMinimumHP(dungeon));
  }
  {
    auto dungeon = vector<vector<int>>{
        {0},
    };
    ASSERT_EQ(1, Solution().calculateMinimumHP(dungeon));
  }
  {
    auto dungeon = vector<vector<int>>{
        {100},
    };
    ASSERT_EQ(1, Solution().calculateMinimumHP(dungeon));
  }
  {
    auto dungeon = vector<vector<int>>{
        {-3, 5},
    };
    ASSERT_EQ(4, Solution().calculateMinimumHP(dungeon));
  }
}

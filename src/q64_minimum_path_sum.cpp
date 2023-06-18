#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
#if 0
  int minPathSum(vector<vector<int>>& grid) {
    auto m = grid.size();
    auto n = grid[0].size();
    auto dp = vector<vector<int>>(m, vector<int>(n));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
    for (int i = 1; i < n; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }

    return dp[m - 1][n - 1];
  }
#else
  int minPathSum(vector<vector<int>>& grid) {
    auto m = grid.size();
    auto n = grid[0].size();

    for (int i = 1; i < m; ++i) grid[i][0] += grid[i - 1][0];
    for (int i = 1; i < n; ++i) grid[0][i] += grid[0][i - 1];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    return grid[m - 1][n - 1];
  }
#endif
};

TEST(Q64_MIN_PATH_SUM, 1) {
  {
    auto grid = vector<vector<int>>{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    ASSERT_EQ(7, Solution().minPathSum(grid));
  }
  {
    auto grid = vector<vector<int>>{
        {1, 2, 3},
        {4, 5, 6},
    };
    ASSERT_EQ(12, Solution().minPathSum(grid));
  }
}
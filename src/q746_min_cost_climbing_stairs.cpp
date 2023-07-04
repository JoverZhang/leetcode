#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

#include <algorithm>
#include <vector>

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    auto dp = vector<int>(cost.size(), 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < cost.size(); ++i) {
      dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    cout << dp << endl;
    return std::min(dp[cost.size() - 1], dp[cost.size() - 2]);
  }
};

TEST(Q746_MIN_COST_CLIMBING_STAIRS, 1) {
  {
    vector<int> cost = {10, 15, 20};
    EXPECT_EQ(Solution().minCostClimbingStairs(cost), 15);
  }
  {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    EXPECT_EQ(Solution().minCostClimbingStairs(cost), 6);
  }
  {
    vector<int> cost = {0, 2, 2, 1};
    EXPECT_EQ(Solution().minCostClimbingStairs(cost), 2);
  }
}

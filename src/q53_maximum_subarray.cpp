#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
#if 0
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    auto sum = nums[0];
    auto result = sum;

    for (int i = 1; i < nums.size(); ++i) {
      auto curr = nums[i];
      if (sum + curr > curr) {
        sum += curr;
      } else {
        sum = curr;
      }
      result = max(sum, result);
    }

    return result;
  }
#else
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];

    auto dp = new int[nums.size()];
    dp[0] = nums[0];
    auto result = dp[0];

    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      result = max(result, dp[i]);
    }

    return result;
  };
#endif
};

TEST(Q53_MAXIMUM_SUBARRAY, 1) {
  {
    auto nums = vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ASSERT_EQ(6, Solution{}.maxSubArray(nums));
  }
  {
    auto nums = vector<int>{1};
    ASSERT_EQ(1, Solution{}.maxSubArray(nums));
  }
  {
    auto nums = vector<int>{5, 4, -1, 7, 8};
    ASSERT_EQ(23, Solution{}.maxSubArray(nums));
  }
}
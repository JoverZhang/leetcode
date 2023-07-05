#include <gtest/gtest.h>
#include <leetcode_utils/utils.h>

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto list = vector<vector<int>>();

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = static_cast<int>(nums.size()) - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          list.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }

          while (left < right && nums[right] == nums[right + 1]) {
            right--;
          }
        }
      }
    }

    return list;
  }
};

/**
 * -4 -1 -1 0 1 2
 */

TEST(Q15_3SUM, 1) {
  Solution s;
  {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    EXPECT_EQ(s.threeSum(nums), expected);
  }
  {
    vector<int> nums = {0, 1, 1};
    vector<vector<int>> expected = {};
    EXPECT_EQ(s.threeSum(nums), expected);
  }
  {
    vector<int> nums = {0, 0, 0};
    vector<vector<int>> expected = {{0, 0, 0}};
    EXPECT_EQ(s.threeSum(nums), expected);
  }
}

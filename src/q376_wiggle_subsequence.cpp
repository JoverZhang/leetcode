#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() < 2) {
      return static_cast<int>(nums.size());
    }

    bool incr;
    int n = 1;
    int i;
    for (i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        incr = true;
        n++;
        break;
      } else if (nums[i] < nums[i - 1]) {
        incr = false;
        n++;
        break;
      }
    }

    for (i = i + 1; i < nums.size(); ++i) {
      if (incr) {
        if (nums[i - 1] > nums[i]) {
          n++;
          incr = false;
        }
      } else {
        if (nums[i - 1] < nums[i]) {
          n++;
          incr = true;
        }
      }
    }

    return n;
  }
};

TEST(Q376_WIGGLE_SUBSEQUENCE, 1) {
  {
    auto nums = vector<int>{1, 7, 4, 9, 2, 5};
    ASSERT_EQ(6, Solution{}.wiggleMaxLength(nums));
  }
  {
    auto nums = vector<int>{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    ASSERT_EQ(7, Solution{}.wiggleMaxLength(nums));
  }
  {
    auto nums = vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(2, Solution{}.wiggleMaxLength(nums));
  }
}
#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class TwoSumBest {
 public:
  static vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; auto num : nums) {
      if (auto search = map.find(target - num); search != map.end()) {
        return {search->second, i};
      }

      map.try_emplace(num, i++);
    }

    return {};
  }
};

TEST(Q1_TWO_SUM, 1) {
  vector v1{2, 7, 11, 15};
  auto result1 = TwoSumBest::twoSum(v1, 9);

  for (auto e : result1) {
    cout << e << ' ';
  }
  cout << endl;
}

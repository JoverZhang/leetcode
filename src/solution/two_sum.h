#pragma once

#include <leetcode_utils/utils.h>

class TwoSumBest {
 public:
  static vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;

    for (int i = 0; auto num : nums){
      if (auto search = map.find(target - num); search != map.end()) {
        return { search->second, i };
      }

      map.try_emplace(num, i++);
    }

    return {};
  }
};

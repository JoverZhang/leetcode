#include "../solution/two_sum.h"

void two_sum_test() {
  vector v1{ 2, 7, 11, 15 };
  auto result1 = TwoSumBest::twoSum(v1, 9);


  for (auto e : result1) {
    cout << e << ' ';
  }
  cout << endl;
}

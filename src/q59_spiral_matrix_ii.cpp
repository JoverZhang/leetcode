#include <leetcode_utils/utils.h>
#include <gtest/gtest.h>

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix{static_cast<size_t>(n), vector<int>(n)};
    int count = 1;
    int edge = 0;
    while (n > 0) {
      if (n == 1) {
        matrix[edge][edge] = count;
        break;
      }

      for (int i = 0; i < n - 1; ++i) {
        matrix[edge][i + edge] = count++;
      }
      for (int i = 0; i < n - 1; ++i) {
        matrix[i + edge][edge + n - 1] = count++;
      }
      for (int i = n - 1; i > 0; --i) {
        matrix[edge + n - 1][i + edge] = count++;
      }
      for (int i = n - 1; i > 0; --i) {
        matrix[i + edge][edge] = count++;
      }

      n -= 2;
      edge += 1;
    }
    return matrix;
  }
};

TEST(Q59_SPIRAL_MATRIX_II, 1) {
  {
    vector<vector<int>> v{{1}};
    ASSERT_EQ(v, Solution{}.generateMatrix(1));
  }
  {
    vector<vector<int>> v{{1, 2, 3, 4},
                          {12, 13, 14, 5},
                          {11, 16, 15, 6},
                          {10, 9, 8, 7}};
    ASSERT_EQ(v, Solution{}.generateMatrix(4));
  }
  {
    vector<vector<int>> v{{1, 2, 3, 4},
                          {12, 13, 14, 5},
                          {11, 16, 15, 6},
                          {10, 9, 8, 7}};
    ASSERT_EQ(v, Solution{}.generateMatrix(4));
  }
}

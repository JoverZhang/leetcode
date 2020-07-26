#ifndef LEETCODE_ZIGZAG_CONVERSION_H
#define LEETCODE_ZIGZAG_CONVERSION_H

#include <leetcode_utils//utils.h>

class ZigZagConversionBest {
 public:
  static string convert(string s, int numRows) {
    string res = s;
    if (numRows == 1) return res;

    int i = 0;
    int diff = (numRows - 1) * 2;

    for (int row = 0; row < numRows; row++) {
      for (int res_i = row; res_i < s.size(); i++) {
        res[i] = s[res_i];

        if (row > 0 && row < numRows - 1) {
          int tmp = res_i + diff - (res_i % diff) * 2;
          if (tmp >= s.size()) {
            i++;
            break;
          }
          res[++i] = s[tmp];
        }
        res_i += diff;
      }
    }

    return res;
  }
};

class ZigZagConversion {
 public:
  static string convert(string s, int numRows) {
    if (s.size() <= numRows || numRows == 1) {
      return s;
    }
    vector<string> block(numRows);

    int curRow = 0;
    bool goingDown = false;

    for (auto c : s) {
      block[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1) {
        goingDown = !goingDown;
      }
      curRow += goingDown ? 1 : -1;
    }

    string result;
    for (string line : block) {
      result += line;
    }

    return result;
  }
};

#endif //LEETCODE_ZIGZAG_CONVERSION_H

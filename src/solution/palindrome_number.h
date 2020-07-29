#pragma once

#include <leetcode_utils/utils.h>

class PalindromeNumberBest {
 public:
  static bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      if (revertedNumber > INT_MAX / 10 || (revertedNumber == INT_MAX / 10 && (revertedNumber % 10) > 7)) {
        return false;
      }

      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
  }
};

class PalindromeNumber {
 public:
  static bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      revertedNumber = revertedNumber * 10 + x % 10;
      x /= 10;
    }

    return x == revertedNumber || x == revertedNumber / 10;
  }
};

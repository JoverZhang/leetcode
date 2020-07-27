#pragma once

#include <leetcode_utils//utils.h>

class ReverseIntegerBest {
 public:
  static int reverse(int x) {
    long long res = 0;
    while (x) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res;
  }

};

class ReverseInteger {
 public:
  static int reverse(int x) {
    if (x > -10 && x < 10) {
      return x;
    }

    long n = x;
    const int maxDepth = 10;
    bool isNegative = n < 0;
    if (isNegative) {
      n = ~n + 1;
    }

    long number[10] = {};
    long cumulativeSum = 0;

    for (int depth = 0; depth < maxDepth; ++depth) {
      long one = ((n % (10 * long(pow(10, depth)))) - cumulativeSum) / long(pow(10, depth));
      number[depth] = one;
      cumulativeSum += one;
    }

    long result = 0;
    for (int i = 0, flag = -1; i < maxDepth; ++i) {
      long cur = number[maxDepth - i - 1];
      if (flag == -1 && cur > 0) {
        flag = 0;
      }
      if (flag >= 0) {
        result += cur * long(pow(10, flag));
        flag++;
      }
    }

    if (isNegative) {
      result = ~result + 1;
    }

    return INT_MIN < result && result < INT_MAX ? result : 0;
  }

};

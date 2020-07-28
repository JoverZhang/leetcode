#pragma once

#include <leetcode_utils/utils.h>

class StringToIntegerBest {
 public:
  static int myAtoi(string str) {
    bool neg = false;
    int start = 0;
    while (str[start] == ' ')
      start++;

    if (str[start] == '-' || str[start] == '+') {
      neg = str[start] == '-';
      start++;
    }

    long long nr = 0;
    bool ok = false;

    while (start < str.size() && isdigit(str[start]) && !ok) {
      if (nr > INT_MAX)
        ok = true;

      nr = nr * 10 + (str[start] - '0');
      start++;
    }

    if (neg)
      nr *= -1;

    if (nr > INT_MAX) {
      return INT_MAX;
    } else if (nr < INT_MIN) {
      return INT_MIN;
    }
    return nr;
  }
};

class StringToInteger {
 public:
  static int myAtoi(string str) {
    string s = trim(str);
    if (s.size() == 0) {
      return 0;
    }
    bool isNegative = false;
    if (s[0] == '-' || s[0] == '+') {
      isNegative = s[0] == '-';
      s = s.substr(1);
    }

    long long result = 0;

    for (auto c : s) {
      if (result > INT_MAX) {
        break;
      }
      result = result * 10 + (c - 48);
    }

    if (isNegative) {
      result = ~result + 1;
    }

    if (result <= INT_MIN) {
      return INT_MIN;
    } else if (result >= INT_MAX) {
      return INT_MAX;
    }
    return result;
  }

  static string trim(string str) {
    string *result = new string;
    int i = 0,
        len = str.size();
    bool isNegative = false;

    for (; i < len; ++i) {
      if (48 <= str[i] && str[i] <= 57) {// in [1, 9]
        break;
      } else if (str[i] == '-' || str[i] == '+') {
        isNegative = str[i] == '-';
        ++i;
        break;
      } else if (str[i] != ' ') {
        return *result;
      }
    }

    int start = i;
    for (; i < len; ++i) {
      if (str[i] < 48 || 57 < str[i]) {
        break;
      }
    }

    if (isNegative) {
      *result += "-";
    }

    *result += str.substr(start, i - start);

    return *result;
  }
};

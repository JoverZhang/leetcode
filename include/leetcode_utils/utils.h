#pragma once

#include "./executor.h"
#include "./print.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using lc_utils::Executor;
using lc_utils::print;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pow;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

template <typename S>
std::ostream &operator<<(std::ostream &os, const vector<S> &vector) {
  for (auto element : vector) {
    os << element << " ";
  }
  return os;
}

template <typename S>
std::ostream &operator<<(std::ostream &os, const vector<vector<S>> &vector) {
  for (auto element : vector) {
    os << element << endl;
  }
  return os;
}

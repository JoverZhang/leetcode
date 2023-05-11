#pragma once

#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <unordered_map>
#include "./print.h"
#include "./executor.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::min;
using std::max;
using std::pow;
using lc_utils::print;
using lc_utils::Executor;

template<typename S>
std::ostream& operator<<(std::ostream& os,
                         const vector<S>& vector) {
  for (auto element : vector) {
    os << element << " ";
  }
  return os;
}

template<typename S>
std::ostream& operator<<(std::ostream& os,
                         const vector<vector<S>>& vector) {
  for (auto element : vector) {
    os << element << endl;
  }
  return os;
}

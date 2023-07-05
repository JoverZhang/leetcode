#pragma once

#include <iostream>

using std::cout;
using std::endl;

namespace lc_utils {

class print {
public:
  print() { cout << endl; }

  template <typename T, typename... TAIL> print(const T &t, TAIL... tail) {
    cout << t << ' ';
    print(tail...);
  }
};

} // namespace lc_utils

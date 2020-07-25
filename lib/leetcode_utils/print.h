#ifndef LEETCODE_PRINT_H
#define LEETCODE_PRINT_H

#include <ostream>

using std::cout;
using std::endl;

namespace lc_utils {

class print {
 public:
  print() {
    cout << endl;
  }

  template <typename T, typename ...TAIL>
  print(T &t, TAIL ...tail) {
    cout << t << ' ';
    print(tail...);
  }
};

}

#endif //LEETCODE_PRINT_H

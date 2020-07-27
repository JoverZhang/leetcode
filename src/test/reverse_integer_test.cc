#include "../solution/reverse_integer.h"

void reverse_integer_test() {
  Executor executor(ReverseIntegerBest::reverse);
  executor
      .exec(123)
      .exec(-123)
      .exec(120)
//      .exec(100)
//      .exec(1)
//      .exec(100)
//      .exec(1002)
//      .exec(-2147483641)
//      .exec(1534236469)
//      .exec(-2147483648)
    //
      ;
  return;
}

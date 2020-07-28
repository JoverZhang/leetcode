#include "../solution/string_to_integer.h"

void string_to_integer_test() {
  Executor executor(StringToIntegerBest::myAtoi);
  executor
      .exec("42")
      .exec("   -42")
      .exec("4193 with words")
      .exec("words and 987")
      .exec("-91283472332")
//      .exec("0")
//      .exec("-000000000000001")
//      .exec("0-1")
    //
      ;
}

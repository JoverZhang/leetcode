#include "../solution/palindrome_number.h"

void palindrome_number_test() {
  Executor executor(PalindromeNumberBest::isPalindrome);
  executor
      .exec(121)
      .exec(-121)
      .exec(10)
    //
      ;
}

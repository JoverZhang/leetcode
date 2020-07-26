#ifndef LEETCODE_TEST_TOOL_H
#define LEETCODE_TEST_TOOL_H

#include "./utils.h"

namespace lc_utils {

template <typename PARAMS_LIST, typename INVOKE>
void batch_invoke(PARAMS_LIST paramsList, INVOKE invoke) {
  for (auto args : paramsList) {
    print(invoke(args.s, args.numRows));
  }
}

}
#endif //LEETCODE_TEST_TOOL_H

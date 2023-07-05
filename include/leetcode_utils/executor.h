#pragma once

#include "./print.h"

namespace lc_utils {

template <typename Invoke> class Executor {
public:
  explicit Executor(Invoke invoke) : invoke_(invoke), openPrint_(true) {}

  Executor(Invoke invoke, bool openPrint)
      : invoke_(invoke), openPrint_(openPrint) {}

  template <typename... ARGS> Executor exec(ARGS... args) {
    if (openPrint_) {
      print(invoke_(args...));
    } else {
      invoke_(args...);
    }
    return *this;
  }

protected:
  Invoke invoke_;
  bool openPrint_;
};

} // namespace lc_utils

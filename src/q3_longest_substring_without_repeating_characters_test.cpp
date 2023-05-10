#include <leetcode_utils/utils.h>

class LongestSubstringWithoutRepeatingCharactersBest {
 public:
  static int lengthOfLongestSubstring(string s) {
    int lastLocation[255];
    memset(lastLocation, -1, sizeof(lastLocation));
    int start = 0;
    int cur = 0;
    int maxLength = 0;
    while (cur < s.length()) {
      char c = s.at(cur);
      if (lastLocation[c] < start || lastLocation[c] == cur)
        lastLocation[c] = cur++;
      else {
        maxLength = max(maxLength, cur - start);
        start = lastLocation[c] + 1;
      }
    }
    maxLength = max(maxLength, cur - start);
    return maxLength;
  }
};

int main() {
  Executor executor(LongestSubstringWithoutRepeatingCharactersBest::lengthOfLongestSubstring);
  executor
      .exec("abcabcbb")
      .exec("bbbbb")
      .exec("pwwkew")
    //
      ;

  return 0;
}
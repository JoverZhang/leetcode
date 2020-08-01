#include "../solution/longest_substring_without_repeating_characters.h"

void longest_substring_without_repeating_characters_test() {
  Executor executor(LongestSubstringWithoutRepeatingCharactersBest::lengthOfLongestSubstring);
  executor
      .exec("abcabcbb")
      .exec("bbbbb")
      .exec("pwwkew")
    //
      ;
}
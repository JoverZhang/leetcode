#include<stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
  string findPalingdrome(string s, int left, int right) {
    int n = s.size();
    while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
      left--;
      right++;
    }
    return s.substr(left + 1, right - left - 1);
  }

  string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) return s;

    string longest;

    string str;
    for (int i = 0; i < n - 1; i++) {
      str = findPalingdrome(s, i, i);
      if (str.size() > longest.size()) {
        longest = str;
      }
      str = findPalingdrome(s, i, i + 1);
      if (str.size() > longest.size()) {
        longest = str;
      }
    }

    return longest;
  }
};



int main() {
  Solution s;
  cout << s.longestPalindrome("babad") << endl;
  cout << s.longestPalindrome("bbabbsahodifaabaa") << endl;
  cout << s.longestPalindrome("cbbd") << endl;
  return 0;
}

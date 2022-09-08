#include <stdio.h>
#include <iostream>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    bool first_match = (!s.empty()) && (p[0] == s[0] || p[0] == '.');

    if (p.size() >= 2 && p[1] == '*') {
      return
        // match zero element
        (isMatch(s, p.substr(2)) ||
          (first_match && isMatch(s.substr(1), p)));
    }

    return first_match && isMatch(s.substr(1), p.substr(1));
  }
};


int main() {
  Solution s;
  cout <<	s.isMatch("aa", "a") << endl;
  cout <<	s.isMatch("aa", "a*") << endl;
  cout <<	s.isMatch("ab", ".*") << endl;
	return 0;
}


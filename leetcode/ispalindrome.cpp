#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    s.erase(remove_if(s.begin(), s.end(),
                      [](auto const c) -> bool { return !isalnum(c); }),
            s.end());
    
    int n = s.size();
    int end = n - 1;
    int start = 0;
    while (end > start) {
      if (tolower(s[start]) != tolower(s[end]))
        return false;
      end--;
      start++;
    }
    return true;
  }
};

int main() {
  string l;
  std::getline(std::cin, l);
  Solution a;
  bool output = a.isPalindrome(l);
  cout << output << endl;
}

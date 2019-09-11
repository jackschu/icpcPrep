#include <iostream>
#include <stack>
#include <string>

#define DEBUG if (false)

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    int n = s.size();
    if (n == 0)
      return true;
    stack<char> opens;
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        opens.push(c);
      } else {
        if (opens.empty()) {
          return false;
        }
        char match = opens.top();
        opens.pop();
        if (c == ')' && match != '(')
          return false;
        if (c == ']' && match != '[')
          return false;
        if (c == '}' && match != '{')
          return false;
      }
    }
    return opens.empty();
  }
};

int main() {
  string l;
  getline(cin, l);
  Solution a;
  bool output = a.isValid(l);
  cout << output << endl;
}

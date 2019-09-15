#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int n = s.size();
    if (t.size() != n)
      return false;
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++) {
      map[s[i]]++;
      map[t[i]]--;
    }
    for (auto elem : map) {
      if (elem.second != 0)
        return false;
    }
    return true;
  }
};

int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  Solution a;
  bool output = a.isAnagram(s, t);
  cout << output << endl;
}

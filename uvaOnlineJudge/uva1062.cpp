#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

bool sort_s(const stack<char> &i, const stack<char> &j) {
  return i.top() < j.top();
}

int try_num(int num, queue<char> &q, vector<stack<char>> &stacks) {
  int n = q.size();
  DEBUG cout << num << n << endl;

  while (!q.empty()) {
    sort(stacks.begin(), stacks.end(), sort_s);
    for (int i = 0; i < num; i++) {
      DEBUG cout << i << " ";
      DEBUG cout << stacks[i].top();
      DEBUG cout << endl;
    }
    char cur = q.front();
    DEBUG cout << "cur " << cur << endl;
    q.pop();
    bool good = false;
    for (int i = 0; i < num; i++) {
      if (cur <= stacks[i].top()) {
        good = true;
        stacks[i].push(cur);
        break;
      }
    }
    if (!good && num == 26)
      return -1;
    if (!good){
      stacks.push_back({});
      stacks[num].push(cur);
      return try_num(num+1, q, stacks);
    }
  }
  return num;
}

int main() {
  int case_num = 0;
  string s;
  while (getline(cin, s)) {
    if (s == "end") break;
    case_num++;
    int n = s.size();
    queue<char> q;
    for (int i = 0; i < n; i++)
      q.push(s[i]);
    vector<stack<char>> stacks;
    stacks.push_back({});
    stacks[0].push(q.front());
    q.pop();
    int x  =try_num(1, q, stacks);
    printf("Case %d: %d\n", case_num, x);
  }
}

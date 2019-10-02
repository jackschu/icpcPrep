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
struct info {
  stack<char> st;
  string s;
  char c;
  int buf, rem, start_idx, targ_idx;
};

void run_case(const string &start, const string &targ) {
  vector<string> sol;
  int n = start.size();
  if (n != targ.size())
    return;
  stack<char> st;
  stack<info> visit;
  unordered_set<string> visited;
  visited.insert("i");
  info begin;
  begin.s = "";
  begin.c = 'i';
  begin.buf = 0;
  begin.rem = 2 * n;
  begin.start_idx = 0;
  begin.targ_idx = 0;
  visit.push(begin);
  while (!visit.empty()) {
    auto cur = visit.top();
    visit.pop();
    if (cur.c == 'i') {
      cur.buf++;
    } else {
      cur.buf--;
    }
    if (cur.buf < 0)
      continue;
    cur.rem--;
    if (cur.c == 'i') {
      cur.st.push(start[cur.start_idx]);
      cur.start_idx++;
    } else {
      if (cur.st.top() != targ[cur.targ_idx])
        continue;
      cur.targ_idx++;
      cur.st.pop();
    }
    if (cur.rem == 0) {
      string ssol = cur.s + cur.c;
      sol.push_back(ssol);
      continue;
    }
    if (cur.buf != cur.rem) {
      string inc = cur.s + cur.c + 'i';
      if (visited.find(inc) == visited.end()) {
        visited.insert(inc);
        info next = cur;
        next.s = cur.s + cur.c;
        next.c = 'i';
        visit.push(next);
      }
    }
    string inco = cur.s + cur.c + 'o';
    if (visited.find(inco) == visited.end()) {
      visited.insert(inco);
      info next = cur;
      next.s = cur.s + cur.c;
      next.c = 'o';
      visit.push(next);
    }
  }
  sort(sol.begin(), sol.end());
  for (auto path : sol) {
    for (int i = 0; i < 2 * n - 1; i++) {
      printf("%c ", path[i]);
    }
    printf("%c\n", path[2 * n - 1]);
  }
}

int main() {
  string start;
  while (getline(cin, start)) {
    while (start.size() == 0) {
      if (!getline(cin, start))
        return 0;
    }
    string targ;
    getline(cin, targ);
    while (targ.size() == 0) {
      if (!getline(cin, targ))
        return 0;
    }
    cout << "[" << endl;

    run_case(start, targ);

    cout << "]" << endl;
  }
}

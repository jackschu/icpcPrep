#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

int N = 8;

inline char rot(char c) {
  if (c == 'F')
    return 'A';
  else
    return c + 1;
}

string get_next(int x, const string &w) {
  char *out = new char[9];
  strcpy(out, w.c_str());
  char c = w[x - 1];
  switch (c) {
  case 'A':
    if (x != 1) {
      out[x - 2] = rot(w[x - 2]);
    }
    if (x != 8) {
      out[x] = rot(w[x]);
    }
    break;
  case 'B':
    if (x == 1 || x == 8)
      break;
    else {
      out[x] = w[x - 2];
      break;
    }
  case 'C':
    out[9 - x - 1] = rot(w[9 - x - 1]);
    break;
  case 'D':
    if (x == 1 || x == 8)
      break;
    else {
      if (x < 5) {
        for (int i = 0; i < x - 1; i++) {
          out[i] = rot(w[i]);
        }
      } else {
        for (int i = x; i < N; i++) {
          out[i] = rot(w[i]);
        }
      }
      break;
    }
  case 'E':
    if (x == 1 || x == 8)
      break;
    else {
      int y = min(x - 1, 8 - x);
      out[x - y - 1] = rot(w[x - y - 1]);
      out[x + y - 1] = rot(w[x + y - 1]);
      break;
    }
  case 'F':
    if (x % 2 == 1) {
      out[(x + 9) / 2 - 1] = rot(w[(x + 9) / 2 - 1]);
    } else {
      out[x / 2 - 1] = rot(w[x / 2 - 1]);
    }
    break;
  }
  string t = string(out, out + 8);
  delete[] out;
  return t;
}

int main() {
  string start, targ;
  getline(cin, start);
  getline(cin, targ);
  if (start == targ) {
    cout << 0 << endl;
    return 0;
  }
  unordered_set<string> visited;
  queue<pair<string, int>> st;
  st.push(pair<string, int>(start, 0));
  visited.insert(start);

  while (!st.empty()) {
    auto p = st.front();
    string cur = p.first;
    int d = p.second;
    DEBUG cout << d << " " << cur << endl;
    st.pop();
    for (int i = 1; i < 9; i++) {
      string out = get_next(i, cur);
      if (out == targ) {
        cout << d + 1 << endl;
        return 0;
      }
      if (visited.find(out) == visited.end()) {
        visited.insert(out);
        st.push(pair<string, int>(out, d + 1));
      }
    }
  }
}

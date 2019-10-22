#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  vi sol;
  vi mem;
  int x;
  cin >> x;
  mem.push_back(x);
  sol.push_back(-1);
  vi mem_id;
  int i = 1;
  int end = 0;
  vi ns;
  ns.push_back(x);
  mem_id.push_back(0);
  while (cin >> x) {
    mem_id.push_back(-1);
    ns.push_back(x);
    auto found = lower_bound(mem.begin(), mem.end(), x);
    int idx = found - mem.begin();

    if (found == mem.end()) {
      mem.push_back(x);
    } else {
      mem[idx] = x;
    }
    mem_id[idx] = i;
    if (idx == mem.size() - 1)
      end = i;
    sol.push_back(idx ? mem_id[idx - 1] : -1);
    i++;
    // cout << "ns ";
    // for (auto elem : ns)
    //   cout << elem << " ";
    // cout << endl;
    // cout << "mem ";
    // for (auto elem : mem)
    //   cout << elem << " ";
    // cout << endl;
    // cout << "mem_id ";
    // for (auto elem : mem_id)
    //   cout << elem << " ";
    // cout << endl;
    // cout << "sol ";
    // for (auto elem : sol)
    //   cout << elem << " ";
    // cout << endl;
  }
  cout << mem.size() << endl;
  cout << "-" << endl;
  stack<int> out;
  int c = end;
  out.push(c);
  while (sol[c] != -1) {
    c = sol[c];
    out.push(c);
  }
  while (!out.empty()) {
    cout << ns[out.top()] << endl;
    out.pop();
  }
}

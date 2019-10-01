#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;

struct Team {
  int solved = 0;
  int time = 0;
  int id;
  vector<int> attempt;

  Team(int id) : id(id) { attempt = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; }
  void print() { printf("%d %d %d\n", id, solved, time); }
};

bool teamSort(Team &i, Team &j) {
  if (i.solved != j.solved)
    return i.solved > j.solved;
  if (i.time != j.time)
    return i.time < j.time;
  return i.id < j.id;
}

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  string l;
  getline(cin, l);

  for (int case_num = 0; case_num < tc; case_num++) {
    if (case_num != 0)
      cout << endl;
    vector<Team> ts;
    ts.reserve(100);
    for (int i = 0; i < 101; i++) {
      ts.push_back(Team(i));
    }
    bool *seen = new bool[101]();
    while (getline(cin, l)) {
      if (l.size() == 0)
        break;
      stringstream ss(l);
      int team;
      int p;
      int time;
      char res;
      ss >> team >> p >> time >> res;
      seen[team] = true;
      Team &got = ts[team];
      if (res != 'C' && res != 'I')
        continue;
      if (res == 'C') {
        if (got.attempt[p] != -1) {
          got.time += got.attempt[p] * 20 + time;
          got.attempt[p] = -1;
          got.solved++;
        }
      } else if (res == 'I') {
        if (got.attempt[p] != -1) {
          got.attempt[p] += 1;
        }
      }
    }
    vector<Team> v;
    for (int i = 0; i < 101; i++) {
      if (seen[i])
        v.push_back(ts[i]);
    }
    delete[] seen;
    sort(v.begin(), v.end(), teamSort);
    for (auto &elem : v) {
      elem.print();
    }
  }
}

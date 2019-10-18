#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m;
bool arr[200][200];
string s;
stringstream ss;
int sslen;
int spc(int x) {
  if (x < 10)
    printf(" ");
  if (x < 100)
    printf(" ");
  if (x < 1000)
    printf(" ");
  return x;
}
void bmode(int ymin, int ymax, int xmin, int xmax) {
  if (ymin > ymax || xmin > xmax)
    return;
  bool cur = arr[ymin][xmin];

  bool win = true;
  for (int i = ymin; i <= ymax && win; i++) {
    for (int j = xmin; j <= xmax && win; j++) {
      win &= (arr[i][j] == cur);
    }
  }
  if (win) {
    ss << to_string(int(cur));
    sslen++;
    if (sslen == 50) {
      sslen = 0;
      ss << endl;
    }
    return;
  }
  ss << "D";
  sslen++;
  if (sslen == 50) {
    sslen = 0;
    ss << endl;
  }
  int yboard = (ymin + ymax) / 2;
  int xboard = (xmax + xmin) / 2;
  if (ymin == ymax && xmin == xmax)
    return;

  bmode(ymin, yboard, xmin, xboard);
  bmode(ymin, yboard, xboard + 1, xmax);
  bmode(yboard + 1, ymax, xmin, xboard);
  bmode(yboard + 1, ymax, xboard + 1, xmax);
}
int cur;

int dmode(int ymin, int ymax, int xmin, int xmax) {
  if (ymin > ymax || xmin > xmax)
    return 0;

  if (s[cur] != 'D') {
    bool fill = s[cur] == '1';
    for (int i = ymin; i <= ymax; i++) {
      for (int j = xmin; j <= xmax; j++) {
        arr[i][j] = fill;
      }
    }
    cur++;
    return 1;
  }

  int yboard = (ymin + ymax) / 2;
  int xboard = (xmax + xmin) / 2;
  if (ymin == ymax && xmin == xmax)
    return 0;
  cur++;

  dmode(ymin, yboard, xmin, xboard);
  dmode(ymin, yboard, xboard + 1, xmax);
  dmode(yboard + 1, ymax, xmin, xboard);
  dmode(yboard + 1, ymax, xboard + 1, xmax);
  return 0;
}

int main() {
  char mode;
  cin >> mode;

  while (mode != '#') {
    cin >> n >> m;
    stringstream ssin;
    string temp = "";
    ss.str("");
    while (temp != "B" && temp != "D" && temp != "#") {
      cin >> temp;
      if (temp != "B" && temp != "D" && temp != "#") {
        ssin << temp;
      }
    }

    if (mode == 'B') {
      s = "";
      string l = ssin.str();
      int ct = 0;
      sslen = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          arr[i][j] = l[ct++] == '1';
        }
      }
      printf("D%4d%4d\n", n, m);
      bmode(0, n - 1, 0, m - 1);
      cout << ss.str();
      if (sslen != 0)
        cout << endl;
    } else {
      s = ssin.str();
      cur = 0;
      dmode(0, n - 1, 0, m - 1);
      printf("B%4d%4d\n", n, m);
      int newl = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << (arr[i][j] ? '1' : '0');
          if (++newl == 50) {
            newl = 0;
            cout << endl;
          };
        }
      }
      if (newl != 0)
        cout << endl;
    }
    mode = temp[0];
  }
}

#include <bits/stdc++.h>

using namespace std;
#define DEBUG if (false)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool board[6][6];
// t u f b l r
// 0 1 2 3 4 5
vi status = {0, 0, 0, 0, 0, 0};

vi roll_down(vi refs) {
  int temp = refs[0];
  refs[0] = refs[3];
  refs[3] = refs[1];
  refs[1] = refs[2];
  refs[2] = temp;
  return refs;
}

vi roll_right(vi refs) {
  int temp = refs[5];
  refs[5] = refs[0];
  refs[0] = refs[4];
  refs[4] = refs[1];
  refs[1] = temp;
  return refs;
}

vi roll_left(vi refs) {
  int temp = refs[4];
  refs[4] = refs[0];
  refs[0] = refs[5];
  refs[5] = refs[1];
  refs[1] = temp;
  return refs;
}
int dy[] = {0, 0, 1};
int dx[] = {1, -1, 0};
bool visited[6][6];
bool fail = false;
int tot = 0;

void dfs(vi refs, ii pos) {
  DEBUG cout << " start " << endl;
  DEBUG printf("pos %d %d  refs1 %d  %d\n", pos.first, pos.second,
               int(refs.size()), refs[1]);
  if (visited[pos.first][pos.second] || fail)
    return;
  visited[pos.first][pos.second] = true;

  if (status[refs[1]]) {
    fail = true;
    return;
  }
  tot++;
  status[refs[1]]++;
  for (int d = 0; d < 3; d++) {
    ii nextpos = pos;
    nextpos.second += dx[d];
    nextpos.first += dy[d];
    if (nextpos.first < 0 || nextpos.first > 5 || nextpos.second < 0 ||
        nextpos.second > 5)
      continue;
    if (!board[nextpos.first][nextpos.second])
      continue;
    vi nrefs;
    if (d == 2)
      nrefs = roll_down(refs);
    else if (d == 1)
      nrefs = roll_left(refs);
    else if (d == 0)
      nrefs = roll_right(refs);
    DEBUG printf("rolling %d\n", d);
    dfs(nrefs, nextpos);
  }
}
int main() {
  ii cur = ii(-1, -1);
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      char x;
      cin >> x;
      board[i][j] = x == '#';
      if (cur == ii(-1, -1) && x == '#')
        cur = ii(i, j);
    }
  }
  vi refs = {0, 1, 2, 3, 4, 5};
  memset(visited, 0, sizeof visited);
  dfs(refs, cur);
  DEBUG printf("tot %d\n", tot);
  if (!fail && tot == 6)
    cout << "can fold" << endl;
  else
    cout << "cannot fold" << endl;
}

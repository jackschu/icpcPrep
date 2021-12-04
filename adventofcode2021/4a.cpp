#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
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
typedef long long ll;

struct Item {
  bool called;
  int row;
  int col;
};

struct Board {
  int rows[5] = {0};
  int cols[5] = {0};
  // value to item data
  map<int, Item> items;
};

vi readNums() {
  string l;
  getline(cin, l);
  stringstream ss(l);
  vi out;
  string item;
  while (getline(ss, item, ','))
    out.push_back(stoi(item));

  return out;
}

Board readBoard() {
  string l;
  Board out;
  int val;
  for (int i = 0; i < 5; i++) {
    getline(cin, l);
    stringstream ss(l);
    for (int j = 0; j < 5; j++) {
      ss >> val;
      Item item;
      item.called = false;
      item.row = i;
      item.col = j;
      out.items.insert(pair<int, Item>(val, item));
    }
  }
  return out;
}

bool checkWin(const Board &board) {
  for (auto elem : board.rows)
    if (elem == 5)
      return true;
  for (auto elem : board.cols)
    if (elem == 5)
      return true;
  return false;
}

int calcScore(const Board &board, int num) {
  int sum = 0;
  for (auto elem : board.items)
    if (!elem.second.called)
      sum += elem.first;
  return sum * num;
}

int main() {
  vi nums = readNums();
  string l;
  vector<Board> boards;
  while (getline(cin, l))
    boards.push_back(readBoard());
  DEBUG cout << boards.size() << endl;
  DEBUG cout << boards[0].items.size() << endl;
  int win_score = -1;
  for (auto num : nums) {
	DEBUG cout << num << endl;
    if (win_score != -1)
      break;

    for (auto &board : boards) {
      auto iter = board.items.find(num);
      if (iter == board.items.end())
        continue;
      iter->second.called = true;
      board.rows[iter->second.row]++;
      board.cols[iter->second.col]++;

      if (checkWin(board)) {
        win_score = calcScore(board, num);
        printf("won! with score %d\n", win_score);
      }
    }
  }
}

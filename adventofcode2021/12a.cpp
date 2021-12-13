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

vector<bool> getIsLargeMapping(vector<string> &node_names) {
  vector<bool> out;
  for (const auto &name : node_names)
    out.push_back(isupper(name[0]));
  return out;
}

vector<string> getNameMapping(map<string, int> &node_names) {
  vector<string> out(node_names.size(), "");
  for (auto elem : node_names)
    out[elem.second] = elem.first;
  return out;
}

int countWays(const vector<vi> &adj, const vector<bool> &is_large, int start,
              int target, vector<bool> exclude) {
  if (start == target)
    return 1;
  if (!is_large[target])
    exclude[target] = true;
  int out = 0;
  for (auto edge : adj[target]) {
    if (exclude[edge])
      continue;
    out += countWays(adj, is_large, start, edge, exclude);
  }
  return out;
}

int main() {
  string l;
  map<string, int> node_names;
  vector<pair<string, string>> inputs;
  while (getline(cin, l)) {
    auto found = l.find("-");
    string left = l.substr(0, found);
    string right = l.substr(found + 1);
    if (node_names.find(left) == node_names.end())
      node_names.insert(make_pair(left, node_names.size()));
    if (node_names.find(right) == node_names.end())
      node_names.insert(make_pair(right, node_names.size()));

    inputs.push_back(make_pair(left, right));
  }
  sort(inputs.begin(), inputs.end());
  int n = node_names.size();

  vi row;
  vector<vi> adj;

  for (int i = 0; i < n; i++)
    adj.push_back(row);
  for (auto elem : inputs) {
    int left = node_names.find(elem.first)->second;
    int right = node_names.find(elem.second)->second;
    adj[left].push_back(right);
    adj[right].push_back(left);
  }

  auto name_mapping = getNameMapping(node_names);
  int start = 0;
  int end = 0;
  for (int i = 0; i < n; i++) {
    if (name_mapping[i] == "start")
      start = i;
    else if (name_mapping[i] == "end")
      end = i;
  }
  auto size_map = getIsLargeMapping(name_mapping);
  vector<bool> exclude(n, false);
  int out = countWays(adj, size_map, start, end, exclude);
  cout << out << endl;
}

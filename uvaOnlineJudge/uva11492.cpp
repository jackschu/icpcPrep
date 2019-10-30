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

typedef pair<int, ii> iii;

int main() {
  int n;
  cin >> n;
  while (n) {
    unordered_map<string, int> lang_int;
    vector<string> int_lang;
    vector<vector<iii>> adj;
    int ct = 0;
    string starts, stops;
    cin >> starts >> stops;
    for (int i = 0; i < n; i++) {
      string as, bs, cs;
      cin >> as >> bs >> cs;
      int c = cs.size();
      auto af = lang_int.find(as);
      int a, b;
      if (af != lang_int.end())
        a = af->second;
      else {
        a = ct++;
        lang_int[as] = a;
        adj.push_back({});
      }
      auto bf = lang_int.find(bs);
      if (bf != lang_int.end())
        b = bf->second;
      else {
        b = ct++;
        lang_int[bs] = b;
        adj.push_back({});
      }
      unsigned char cf = cs[0] - 'a';
      adj[a].push_back(iii(c, ii(b, (int)cf)));
      adj[b].push_back(iii(c, ii(a, (int)cf)));
    }

    int dist[4050][26];
    int inf = 1e9;
    for (int i = 0; i < 4050; i++)
      for (int j = 0; j < 26; j++)
        dist[i][j] = inf;

    auto startf = lang_int.find(starts);
    auto stopf = lang_int.find(stops);
    if (startf == lang_int.end() || stopf == lang_int.end() ||
        starts == stops) {
      cout << "impossivel" << endl;
      cin >> n;
      continue;
    }
    int start = startf->second;
    int stop = stopf->second;

    priority_queue<iii, vector<iii>, greater<iii>> q;
    DEBUG cout << "start " << start << endl;
    for (auto opt : adj[start]) {
      q.push(opt);
      DEBUG cout << char(opt.second.second + 'a') << endl;
      DEBUG cout << opt.first << endl;
      dist[opt.second.first][opt.second.second] =
          min(opt.first, dist[opt.second.first][opt.second.second]);
    }

    while (!q.empty()) {
      auto cur = q.top();
      q.pop();
      int d = cur.first;
      int lang = cur.second.first;
      int let = cur.second.second;
      if (d > dist[lang][let])
        continue;
      for (auto pv : adj[lang]) {
        int let_v = pv.second.second;
        if (let_v == let)
          continue;
        int lang_v = pv.second.first;
        if (dist[lang][let] + pv.first < dist[lang_v][let_v]) {
          dist[lang_v][let_v] = dist[lang][let] + pv.first;
          q.push(iii(dist[lang_v][let_v], ii(lang_v, let_v)));
        }
      }
    }
    int out = inf;
    for (int i = 0; i < 26; i++) {
      out = min(out, dist[stop][i]);
    }
    if (out == inf)
      cout << "impossivel" << endl;
    else
      cout << out << endl;

    cin >> n;
  }
}

#include <bits/stdc++.h>

using namespace std;
#define DEBUG if (false)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dhash(const vi &v){
  int pow =1;
  int out =0;
  for(int i = 0; i < 6; i++){
    out+=v[i]*pow;
    pow*=6;
  }
  return out;
}

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> m;
  for (int id = 0; id < n; id++) {
    set<int> s;
    vi v;    
    int t, u, f, b, l ,r;
    cin >> t >> u >> f >>b >> l >> r;
    t--; u--; f--; b--; l--; r--;
    for(int i = 0;  i < 4; i++){
      int tempi = l;
      l = f; f = r; r =b; b = tempi;
      for(int j = 0;  j < 4; j++){
	int tempj = u;
	u = f; f = t; t = b; b= tempj;
	for(int k = 0;  k < 4; k++){
	  int tempk = u;
	  u = l; l = t; t = r; r= tempk;
	  v = {t, f, r, b, l, u};
	  s.insert(dhash(v));
	}
      }
    }
    for(auto num : s)
      m[num] ++;
  }
  int out = 1;
  for (auto &p : m) {
    out = max(p.second, out);
  }
  cout << out << endl;
}

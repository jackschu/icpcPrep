#include <algorithm>
#include <bitset>
#include <cctype>
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
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

/**
 * Data structure from competitive programming 3
 */
class UnionFind {
private:
  vi p, rank;
public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      // if from different set
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      // rank keeps the tree short
      else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
};

void run_case(){
  int n;
  cin >> n;
  cin.ignore();
  string l;
  getline(cin, l);
  UnionFind uf(n+1);
  int y_ct =0;
  int n_ct = 0;
  
  while(l.size() != 0){
    stringstream ss(l);
    char c;
    int i,j;
    ss >> c>>i >> j;
    if(c == 'c'){
      uf.unionSet(i,j);
    } else {
      if(uf.isSameSet(i,j)){
	y_ct++;
      } else{
	n_ct++;
      }
    }
    getline(cin,l);
  }
  printf("%d,%d\n", y_ct, n_ct);
}

int main(){
  int tc;
  cin>> tc;
  cin.ignore();
  string l;
  getline(cin, l);
  bool first=  true;
  for(int i= 0; i<tc;i++){
    if(!first) cout << endl;
    first = false;
    run_case();
  }
  
}

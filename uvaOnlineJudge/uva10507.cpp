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
  vi sz;
public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++){
      sz.push_back(1);
      p[i] = i;
    }
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  int getSize(int i) { return sz[findSet(i)]; }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      // if from different set
      int x = findSet(i), y = findSet(j);
      sz[x] += sz[y];
      sz[y] = sz[x];
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


int main(){

  int n;
  while(cin>>n){
    UnionFind uf(26);
    bool ** cons = new bool*[26];
    for(int i = 0; i<26; i++){
      cons[i] = new bool[26]();
    }
    int sects = n;

    int m;
    cin >> m;
    string s;
    cin>> s;
    DEBUG cout << s <<endl;
    int awake = s[0]-'A';
    DEBUG cout << awake <<endl;
    for(auto elem : s)
      uf.unionSet(awake, elem-'A');
    for(int i = 0; i < m;i++){
      char f, t;
      cin >> f>> t;
      cons[f-'A'][t-'A'] = true;
      cons[t-'A'][f-'A'] = true;
    }
    bool repeat =  true;
    int year = 0;
    while(uf.getSize(awake) < sects && repeat){
      year++;
      vi ons;
      repeat = false;
      for(int i = 0; i<26; i++){
	if(uf.isSameSet(i, awake))continue;
	int good= 0;
	for(int j = 0; j<26; j++){
	  if(cons[i][j] && uf.isSameSet(j, awake)){
	    good++;
	  }
	  if(good == 3){
	    ons.push_back(i);
	    repeat = true;
	    break;
	  }
	}
      }
      for(auto elem: ons){
	uf.unionSet(awake,elem);
      }
    }
    if(uf.getSize(awake) < sects){
      DEBUG cout << uf.getSize(awake);
      cout << "THIS BRAIN NEVER WAKES UP"<<endl;
    } else{
      printf("WAKE UP IN, %d, YEARS\n", year);
    }
     
    for(int i = 0; i<26; i++){
      delete [] cons[i];
    }
    delete [] cons;
  }

}

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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  int targ;
  cin>> targ;
  bool * b = new bool[61]();
  for(int i = 0; i <= 20; i++){
    b[i] = true;
    if(i*2 < 61)
      b[i*2] = true;
    if(i*3 < 61)
      b[i*3] = true;
  }
  b[50] = true;
  while(targ > 0){

    if(targ > 180){
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", targ);
      cout << "**********************************************************************" << endl;
cin >> targ;
      continue;
    }
    int perms = 0;
    int combo = 0;
    for(int i = 60; i >= 0; i--){
      if(!b[i]) continue;
      int cur = targ-i;
      if(cur < 0) continue;
      for(int j = i; j >=0;j--){
	DEBUG printf("%d %d\n", i, j);
	if(!b[j]) continue;
	int jcur = cur-j;
	if(jcur <0) continue;
	if(jcur > j || jcur > 60 || !b[jcur]) continue;
	DEBUG printf("%d %d %d\n", i, j, jcur);
	combo++;
	if(jcur == j && j == i){
	  perms++;
	} else if(jcur == j || j == i || i == jcur){
	  perms += 3;
	} else {
	  perms += 6;
	}
      }
    }
    if(combo == 0){
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", targ);
       cout << "**********************************************************************" << endl;
   cin>>targ;
      continue;
    }
    printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", targ, combo);
    printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", targ, perms);
    cout << "**********************************************************************" << endl;
    cin >> targ;
  }
  cout << "END OF OUTPUT" <<endl;
  delete [] b;
}

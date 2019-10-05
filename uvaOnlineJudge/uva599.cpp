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

void run_case(){
  string l;
  bool * seen = new bool[26]();
  int e_ct = 0;
  while(getline(cin,l)){
    if(l[0] == '*') break;
    seen[l[1] - 'A' ] = true;
    seen[l[3] - 'A' ] = true;
    e_ct++;
  }
  getline(cin,l);
  int n = l.size();
  int v_ct = 0;
  int a_ct = 0;
  for(int i = 0; i < n; i+=2){
    v_ct++;
    if(!seen[l[i] - 'A'])
      a_ct++;
  }
  printf("There are %d tree(s) and %d acorn(s).\n", v_ct - e_ct - a_ct, a_ct);
}

int main() {
  int tc;
  cin >> tc;
  cin.ignore();
  for(int i = 0 ; i < tc; i++){
    run_case();
  }
}

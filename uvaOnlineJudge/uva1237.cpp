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


void run_case(){
  int d;
  vector<string> names;
  vii range;
  cin >> d;
  names.reserve(d);
  range.reserve(d);
  for(int i = 0; i < d; i++){
    string s; int a,b;
    cin >> s >> a  >> b;
    names.push_back(s);
    range.push_back(ii(a,b));
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int p;
    cin >> p;
    int found = -1;
    for(int j = 0; j < d; j++){
      if(p >= range[j].first && p <= range[j].second){
	if(found != -1){
	  found = -1;
	  break;
	} else {
	  found = j;
	}
      }
    }
    if(found == -1){
      cout << "UNDETERMINED" <<endl;
    } else {
      cout << names[found] <<endl;
    }
  }
}

int main(){
  int c;
  cin >> c;
  bool first =  true;
  for(int i = 0 ; i < c; i++){
    if(!first) cout << endl;
    first = false;
    run_case();
  }
}

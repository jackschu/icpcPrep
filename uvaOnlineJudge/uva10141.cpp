#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

int main(){
  bool first = true;
  int idx = 0;
  while(true){
    idx++;
    int n, p;
    cin >>n >> p;
    cin.ignore();
    if( n== 0 && p == 0) break;
    if(!first){
      cout <<endl;
    }
    first = false;
    string s;
    for(int i = 0; i<n; i++) getline(cin, s);
    int mx_r = -1;
    int mn_d;
    string sol;
    for(int i = 0; i<p; i++){
      getline(cin, s);
      double d;
      int r;
      cin >> d >> r;
      cin.ignore();
      if( r > mx_r){
	mx_r = r;
	mn_d = d;
	sol = s;
      } else if (r == mx_r){
	if(d < mn_d){
	  mx_r = r;
	  mn_d = d;
	  sol =s;
	}
      }
      for(int j = 0;  j<r; j++) getline(cin,s);
    }
    printf("RFP #%d\n", idx);
    cout << sol <<endl;
  }
}

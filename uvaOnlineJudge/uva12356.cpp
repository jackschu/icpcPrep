#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iterator>
#define DEBUG if(false)
using namespace std;


void one_case(int s, int b){
  unordered_map<int, int> buds_l;
  unordered_map<int, int> buds_r;
  buds_r[s] = -3;
  buds_l[1] = -3;
  for(int lp = 0; lp < b; lp++){
    int l, r;
    cin >> l >> r;
    auto f1 = buds_r.find(r);
    auto f2 = buds_l.find(l);
    int set1 = f1 == buds_r.end() ? r+1 : f1->second;
    int set2 = f2 == buds_l.end() ? l-1 : f2->second;
    buds_r[set2] = set1;
    buds_l[set1] = set2;
    string out1 = set2 == -3 ? "*" : to_string(set2);
    string out2 = set1 == -3 ? "*" : to_string(set1);

    DEBUG cout << endl;
    cout << out1 + " " + out2 << endl;
  }
  cout << "-" << endl;
}

int main(){
  int s, b;
  cin >> s >> b;
  while(s != 0 && b !=0){
    one_case(s,b);
    cin >> s >> b;
  }
}

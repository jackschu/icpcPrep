#include <iostream>
#include <vector>
#include <algorithm>
#define DEBUG if(false)
using namespace std;

struct minion {
  int a;
  int b;
  minion(int a, int b): a(a), b(b){}
  bool sat = false;
  bool check(int x){
    bool out = a <= x && x <= b;
    sat |= out;
    return out;
  }
};
bool sort_min(minion a, minion b) {return a.b <b.b;}

int main(){
  int n;
  cin >>n;
  vector<minion> v;
  for(int i = 0; i<n; i++){
    int a,b;
    cin >> a>> b;
    v.push_back(minion(a,b));
  }
  sort(v.begin(), v.end(), sort_min);
  int out = 0;
  for(int i = 0; i <n; i++){
    if(v[i].sat) continue;
    int cur = v[i].b;
    DEBUG cout << cur << endl;
    out++;
    for(auto& elem: v){
      elem.check(cur);
    }
  }
  cout << out << endl;
}

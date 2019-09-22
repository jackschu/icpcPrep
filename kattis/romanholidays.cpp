#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
string int_to_roman(int x);
int get_pos(int x, vector<string> &copy_rs, unordered_map<string, int> &mem){
  int rest = x % 1000;
  int ms = x / 1000;
  int off = rest == 0 ? 0 : mem[copy_rs[rest-1]];
  int out;
  if(off < 0) {
    out =off - ms*54;
  } else {
    out = off + ms*946;
  }
  return out;
}


string int_to_roman(int x) {


  vector<pair<int, string>> base = {
      pair<int, string>(900, "cm"),  pair<int, string>(800, "dccc"),
      pair<int, string>(700, "dcc"), pair<int, string>(600, "dc"),
      pair<int, string>(500, "d"),   pair<int, string>(400, "cd"),
      pair<int, string>(300, "ccc"), pair<int, string>(200, "cc"),
      pair<int, string>(100, "c"),   pair<int, string>(90, "xc"),
      pair<int, string>(80, "lxxx"), pair<int, string>(70, "lxx"),
      pair<int, string>(60, "lx"),   pair<int, string>(50, "l"),
      pair<int, string>(40, "xl"),   pair<int, string>(30, "xxx"),
      pair<int, string>(20, "xx"),   pair<int, string>(10, "x"),
      pair<int, string>(9, "ix"),    pair<int, string>(8, "viii"),
      pair<int, string>(7, "vii"),   pair<int, string>(6, "vi"),
      pair<int, string>(5, "v"),     pair<int, string>(4, "iv"),
      pair<int, string>(3, "iii"),   pair<int, string>(2, "ii"),
      pair<int, string>(1, "i")};

  string s = "";
  while( x >= 1000){
    s +="m";
    x -= 1000;
  }
  for (int i = 0; i < base.size(); i++) {
    if (x >= base[i].first) {
      s += base[i].second;
      x -= base[i].first;
    }
    if (x == 0)
      break;
  }
  return s;
}

int main() {
  unordered_map<string,int> mem;
  vector<string> rs;
  vector<string> copy_rs;

  rs.reserve(1000);
  copy_rs.reserve(1000);
  for(int i = 1; i < 1001; i++){
    rs.push_back(int_to_roman(i));
  }
  copy(rs.begin(), rs.end(), copy_rs.begin());
  sort(rs.begin(), rs.end());
  for(int i = 1; i < 1001; i++){
    if(i <= 946){
      mem[rs[i-1]] = i;
    } else {
      mem[rs[i-1]] = i- 1001;
    }
  }
  int n;
  cin  >> n;
  for(int i =0 ; i < n; i++){
    int x;
    cin>>x;
    cout << get_pos(x, copy_rs, mem) << endl;;
  }
}

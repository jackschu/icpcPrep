#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#define DEBUG if(false)
using namespace std;

long get_val(int * vals, string &l){
  long out = 0;
  for(unsigned char c : l){
    out += vals[(unsigned int)c];
  }
  return out;
}

void one_case(){
  int k;
  cin >> k;
  int * vals = new int[1000]();
  for(int i = 0; i <k; i++){
    unsigned char c;
    int x;
    cin >> c >> x;
    vals[(unsigned int)(c)] = x;
  }
  int m;
  cin >> m;
  cin.ignore();
  long sum = 0;
  for(int i = 0; i <m; i++){
    string l;
    getline(cin, l);
    sum += get_val(vals, l);
  }
  long front = sum / 100;
  long back = sum % 100;
  cout << front << ".";
  if(back < 10) cout << "0";
  cout <<back << "$" << endl;
  delete [] vals;
}

int main(){
  int N;
  cin >> N;
  for(int i = 0; i<N;i++)
    one_case();
}

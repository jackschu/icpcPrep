#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define DEBUG if(false)
using namespace std;


//solution to https://open.kattis.com/problems/sortofsorting
bool compare_first_two_chars(string i, string j){
  string short_i = i.substr(0,2);
  string short_j = j.substr(0,2);  
  return short_i < short_j;
}
	       

void handle_case(int n){
  vector<string> all_strings;
  for( int i = 0 ; i < n ; i++){
    string temp;
    cin >> temp;
    all_strings.push_back(temp);    
  }
  stable_sort(all_strings.begin(), all_strings.end(), compare_first_two_chars);

  for( int i =0; i <n; i++){
    cout << all_strings[i];
    cout << endl;

  }
}

int main(){
  int n = -1;
  bool first = true;
  while( n != 0){
    cin >> n;
    if( n > 0 && !first){
      cout << endl;
    }
    first = false;

    if(n>0)
      handle_case(n);
  }
}

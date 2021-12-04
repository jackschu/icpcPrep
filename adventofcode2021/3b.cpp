#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define DEBUG if (false)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

void printVec(vector<string> v){
  for (auto &elem :v)
	printf("%s, ", elem.c_str());
  printf("\n");
}

string reduceOnCondition(vector<string> rows, function<bool(int,char)> condition){
  int n = rows[0].size();
  for(int i = 0 ; i <n && rows.size() > 1 ;i++){
	vi ticks(n, 0);
	for(auto &row : rows)
	  for(int i = 0 ; i <n ;i++)
		ticks[i] += row[i] =='1' ? 1 : -1;
	vector<string> new_rows;
	for(auto &row : rows) {
	  if(condition(ticks[i], row[i]))
		new_rows.push_back(row);
	}
	rows = new_rows;
	DEBUG printVec(rows);
  }
  return rows[0];
}

int main() {
  string l;
  vector<string> rows; 
  while (getline(cin, l)) 
	rows.push_back(l);
  auto common_condition = [=](int common_counter, char val){
	if (common_counter >= 0){
	  if(val == '1')
		return true ;
	} else {
	  if(val == '0')
		return true;
	}
	return false;
  };

  auto uncommon_condition = [=](int common_counter, char val){
	return !common_condition(common_counter, val);
  };

  string common_str = reduceOnCondition(rows, common_condition);
  string uncommon_str = reduceOnCondition(rows, uncommon_condition);
  printf("%s %s\n", common_str.c_str(),uncommon_str.c_str());

  int common_num = stoi(common_str, nullptr, 2);
  int uncommon_num = stoi(uncommon_str, nullptr, 2);
  cout << common_num * uncommon_num <<endl;
}

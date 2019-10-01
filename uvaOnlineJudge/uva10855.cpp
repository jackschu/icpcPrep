#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#define DEBUG if (false)
using namespace std;

vector<vector<char>> rotate_matrix( vector<vector<char>> &a){
  int m = a.size();
  vector<vector<char>> out;
  out.reserve(m);
  for(int i = 0; i < m; i++){
    out.push_back({});
    out.reserve(m);
  }

  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      out[j].push_back(a[m-i-1][j]);
    }
  }
  return out;
}

int count_occurances(vector<vector<char>> &nn, vector<vector<char>> &mm){
  int n =  nn.size();
  int m =  mm.size();
  int ct = 0;
  for(int i = 0; i + m - 1 < n; i++){
    for(int j = 0;  j+ m -1 < n; j++){
      bool works = true;
      for(int k = 0; k < m && works; k++){
	for(int l = 0; l < m; l++){
	  if(nn[i+k][j+l] != mm[k][l]){
	    works = false;
	    break;
	  }
	}
      }
      ct += int(works);
    }
  }
  return ct;
}

void print_arr(vector<vector<char>> &a){
    for(auto row: a){
      for(auto elem: row)
	cout << elem << " ";
      cout << endl;
    }
}
int main() {
  int n, m;
  cin >> n >> m;
  while(n != 0 && m != 0){
    vector<vector<char>> nn;
    nn.reserve(n);
    vector<vector<char>> mm;
    mm.reserve(m);
    for(int i = 0; i < n; i++){
      nn.push_back({});
      nn[i].reserve(n);
      copy_n(istream_iterator<char>(cin), n, back_inserter(nn[i]));
    }
    for(int i = 0; i < m; i++){
      mm.push_back({});
      mm[i].reserve(m);
      copy_n(istream_iterator<char>(cin), m, back_inserter(mm[i]));
    }
    cout << count_occurances(nn, mm);
    for(int i = 0; i < 3; i++){
      mm = rotate_matrix(mm);
      cout << " " << count_occurances(nn, mm);
    }
    cout << endl;
    
    cin>> n >> m;
  }
}

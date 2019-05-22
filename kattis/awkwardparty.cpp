#define DEBUG if(false)
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> guests(n);
  unordered_set<int> all_uniq;

  unordered_map<int, int> seen;  
  all_uniq.reserve(n);
  bool repeats = false;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    guests[i] = temp;
    if (!repeats && all_uniq.count(temp) == 1){
      repeats = true;
    }
    all_uniq.insert(temp);
  }
  if (!repeats){
    cout << n << endl;
    return 0;
  }
  int max_min = 1E9;
  int global_offset = 0;
  for(auto elem : guests){
    DEBUG printf("elem %d\n", elem);
    int new_min = -1;
    auto p = seen.find(elem);
    if(p != seen.end()){
      new_min = global_offset - p->second;
      if (new_min < max_min)
	max_min = new_min;
    }
    seen[elem] = global_offset;
    global_offset++;
  }
  cout << max_min << endl;
}
  

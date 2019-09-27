#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#define DEBUG if(false)
using namespace std;

int main(){
  while(true){
    int dur;
    double down;
    double amt;
    int n;
    cin >> dur >> down >> amt >> n;
    if (dur < 0) break;
    queue<pair<int,double>> schd;
    for(int i = 0; i < n; i++){
      int m; double pct;
      cin>> m >> pct;
      schd.push(pair<int,double>(m, pct));
    }
    schd.push(pair<int,double>(dur,0));
    double pct = schd.front().second;
    schd.pop();
    double worth = amt+down;
    worth -= worth*pct;
    double monthly = amt/(double)dur;
    DEBUG printf("w %lf a %lf\n", worth, amt);
    int out = dur;
    for(int i = 1; i < dur; i++){
      if (worth > amt) {
	out = i-1;
	break;
      }
      int nxt = schd.front().first;
      if(i == nxt){
	pct = schd.front().second;
	schd.pop();
      }
      DEBUG printf("pct %lf\n", pct);
      amt -= monthly;
      worth -= worth*pct;
      DEBUG printf("w %lf a %lf\n", worth, amt);
      if (worth > amt) {
	out = i;
	break;
      }

    }
    if(out == 1) printf("%d month\n", out);
    else printf("%d months\n", out);
  
  }
}

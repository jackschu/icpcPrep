#include <iostream>

using namespace std;

int three(int x){
  int count = 1;
  while(x != 1){
    if(x % 2){
      x *= 3;
      x++;
    } else {
      x = x >> 1; 
    }
    count++;
  }
  return count;
}

int main(){
  int x,y;

  while (cin >> x >> y){
    cout << x << " " << y;
    int i = min(x,y);
    y = max(x,y);
    int max = 0;
    for(; i <= y ; i++){
      int z = three(i);
      if(z > max) max = z;
    }
    printf(" %d\n",max);
  }

}

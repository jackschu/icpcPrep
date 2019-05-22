#define DEBUG if(false)
#define HELPING if(true)
#include <iostream>
#include <vector>

using namespace std;

struct line{
  double m;//if line is vertical then this is the x value
  double b;
  bool vert = false;
  line(bool vert, double x): vert(vert), m(x){}
  line(double m, double b) : m(m),b(b){}
  bool are_parallel(const line &other){
    if(this->vert != other.vert)
      return false;
    if (!vert){
      return this->m == other.m;
    } else {
      return true;
    }
  }
  void print(){
    printf("vert? %d, m %f, b%f\n", int(vert), m, b);
  }
};

struct point{
  double x;
  double y;
  point(double x, double y) : x(x), y(y){}
  bool above_line(const line &l){
    if (l.vert){
      return  x <= l.m;
    }
    double line_y = l.m*x + l.b;
    return y <= line_y;
  }
};

int num_non_parallel_pairs(vector<line> lines){
  int out = 0;
  int n = lines.size();
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      out += (int)!lines[i].are_parallel(lines[j]);
    }
  }
  DEBUG printf("num non || %d\n",out);
  return out;
};

//returns true if all regions are protected
bool handleCase(vector<line> lines, vector<point> points){
  
  int n = lines.size();
  int m = points.size();
  int p = num_non_parallel_pairs(lines);
  int regions = p + n + 1;
  vector<vector<point> > point_groups;
  DEBUG printf("num regions %d\n", regions);
  HELPING printf("%d\n", regions);  
  point_groups.push_back(points);
  if (m < regions)
    return false;
  for(auto elem : lines){ //for each line, split point groups
    int covered = point_groups.size();
    for(int i = 0; i < covered; i++){
      vector<point> low_group;
      vector<point> high_group;      
      const vector<point> &cur_group = point_groups[i];
      // for each point group form tentative new groups
      for(int j = 0; j < cur_group.size();j++){
	point cur_point = cur_group[j];
	if (cur_point.above_line(elem)){
	  high_group.push_back(cur_point);
	} else {
	  low_group.push_back(cur_point);
	}	
      }
      // add new group if needed      
      if(high_group.size() == 0 || low_group.size()==0){
	continue;
      }
      DEBUG printf("creating new group\n");
      point_groups[i] = high_group;
      point_groups.push_back(low_group);
    }
  }
  int regions_covered = point_groups.size();
  if (regions_covered >= regions)
    return true;
  else
    return false;
}
  
void handleInput(){
  int n;
  int m;
  cin >> n >> m;
  vector<line> lines;
  for(int i = 0; i < n; i++){
    double a, b,c;
    cin >> a >> b >> c;
    if (b==0){
      line temp(true, -c/a);
      lines.push_back(temp);      
    } else { 
      double temp_m = -a/b;
      double temp_b = -c/b;    
      line temp(temp_m,temp_b);
      lines.push_back(temp);
    }

  }
  vector<point> points;

  for(int i = 0; i < m; i++){
    double x, y;
    cin >> x >> y;
    point temp(x,y);
    points.push_back(temp);
  }
  bool result = handleCase(lines, points);
  if (result)
    cout << "PROTECTED" << endl;
  else
    cout << "VULNERABLE" << endl;
}

int main(){
  int num_cases;
  cin >> num_cases;
  for( int i = 0; i <num_cases; i++){
    handleInput();
  }
  

}

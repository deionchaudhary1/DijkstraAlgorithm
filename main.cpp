#include <iostream>
using namespace std;

class Graph{
int n;
bool vertexSet[6] = {true, false, false, false, false, false};
int weight[6];
//int matrix[6][6];
int INT_MAX = 100000;
int matrix[6][6] = {
    {0, 120, 150, INT_MAX, INT_MAX, 500},
    {120, 0, INT_MAX, 75, INT_MAX, 350},
    {150, INT_MAX, 0, INT_MAX, 250, INT_MAX},
    {INT_MAX, 75, INT_MAX, 0, 150, INT_MAX},
    {INT_MAX, INT_MAX, 250, 150, 0, INT_MAX},
    {500, 350, INT_MAX, INT_MAX, INT_MAX, 0}
};

public:
Graph(){
 n=6;
}

int getSmallest(){
  int v = 1;
  int small = 1;
  for (int i = 0; i<n; i++){
    //small = 1;
      if(!vertexSet[i] /*problem here*/ && weight[small] < weight[i+1]){
        v=small; //this one takes
        //small = small;
      }
      else{
        small = weight[i+1];
        v=i+1;
        small = i+1;
      }
    }
  return v;
}

void shortestPath(){
 //int n = 6;
  int i = 0;
 for (int i = 0; i<n; i++){
 weight[i] = matrix[0][i];
 }
  for(int k = 0; k<n; k++){
     i = getSmallest();
    vertexSet[i] = true;
    for (int u = 0; u<n; u++){
    if (!vertexSet[u] && weight[u] > weight[i] + matrix[i][u]){ 
      weight[u] = weight[i] + matrix[i][u];
      }
    }
  }
  for(int i = 0; i<=5; i++){
    cout<<"Airline "<<i<<" is "<<weight[i]<<endl; 
    cout<<endl;
  }
   }
 
};

int main() {
  Graph g;
  g.shortestPath();
}

/* SAMPLE OUTPUT

Airline 0 is 0

Airline 1 is 120

Airline 2 is 150

Airline 3 is 195

Airline 4 is 345

Airline 5 is 470 */
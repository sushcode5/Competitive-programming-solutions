/*                  
               Name - Rindhe Sushil Samadhan
               IIT Guwahati.

*/

/*

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.

Note : Order of different edges doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

Print the MST, as described in the task.

Constraints :

2 <= V, E <= 10^5
Time Limit: 1 sec

Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

1 2 1
0 1 3
0 3 5


*/

#include <bits/stdc++.h>
using namespace std;
struct Edges{
  int source;
  int destination;
  int weight;
};
bool sortInput(Edges E1,Edges E2){
  return E1.weight <E2.weight;
}
int getparent(int v,int*parent){
  if(parent[v]==v){
    return v;
  }
  return getparent(parent[v],parent);
}
vector<Edges> Kruskals(Edges* input,int V,int E){
  //Sort input array based on weights
  sort(input,input+E,sortInput);
  vector<Edges>output;
  int*parent = new int[V];
  for(int i=0;i<V;i++){
    parent[i]=i;
  }
  int count = 0;
  int i=0;
  // maximum number of edges for MST is V-1.
  while(count<V-1){
    int v1 = input[i].source;
    int v2 = input[i].destination;
    //get parent for v1 and v2
    int parentV1 = getparent(v1,parent);
    int parentV2 = getparent(v2,parent);
    
    if(parentV1!=parentV2){
      output.push_back(input[i]);
      count++;
      parent[parentV2]=parent[parentV1];
    }
    i++;
  }
  delete[]parent;
  return output;
}

int main() {
  int V,E;
  // V is number of Vertices and E is number of Edges
  cin>>V>>E;
  Edges* input=new Edges[E];
  //take the input
  for(int i=0;i<E;i++){
    int vertex1,vertex2, edgeWeight;
    cin>>vertex1>>vertex2>>edgeWeight;
    
    input[i].source=vertex1;
    input[i].destination=vertex2;
    input[i].weight= edgeWeight;
  } 
  // call for function
  vector<Edges>output= Kruskals(input,V,E);
  //Print the output
  for(int i=0;i<output.size();i++){
    if(output[i].source<output[i].destination)
      cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    else
      cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
  }
  delete[]input;
  return 0;
}

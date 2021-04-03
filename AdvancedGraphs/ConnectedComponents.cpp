/*                Name - Rindhe Sushil Samadhan
                  IIT Guwahati
                  
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int>*edges,unordered_set<int>* component,int start,bool* visited){
  visited[start]=true;
  component->insert(start);
  for(int i=0;i<edges[start].size();i++){
    int next = edges[start][i];
    if(!visited[next]){
      DFS(edges,component,next,visited);
    }
  }
}
unordered_set<unordered_set<int>*>*  getComponents(vector<int>*edges,int n){
  bool* visited = new bool[n];
  for(int i=0;i<n;i++){
    visited[i]=false;
  }
  unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
  for(int i=0;i<n;i++){
    if(!visited[i]){
      unordered_set<int>* component = new unordered_set<int>();
      DFS(edges,component,i,visited);
      output ->insert(component);
    }
  }
  delete []visited;
  return output;
}
int main(){
  int n;
  cin>>n;  
  vector<int>*edges = new vector<int>[n];
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int j,k;
    cin>>j>>k;
    // take vertices from 1 to N
    edges[j-1].push_back(k-1);
    edges[k-1].push_back(j-1);
  }
  unordered_set<unordered_set<int>*>* components = getComponents(edges,n);
  unordered_set<unordered_set<int>*> :: iterator itr = components->begin();
  while(itr!=components->end()){
    unordered_set<int>* component = *itr;
    unordered_set<int>:: iterator it = component->begin();
    while(it!=component->end()){
      cout<<*it+1<<" ";
      it++;
    }
    cout<<endl;
    delete component;
    itr++;
  }
  delete components;
}

                                                                                                                                                                            

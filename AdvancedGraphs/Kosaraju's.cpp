/*        
                    Name - Rindhe Sushil Samadhan
                    IIT Guwahati
 
 */


#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>*edges,int start,unordered_set<int>& visited,stack<int> &finishedVertices,int n){
    visited.insert(start);
   
    for(int i=0;i<edges[start].size();i++){
        int adjacent = edges[start][i];
        if(visited.count(adjacent)==0){
            dfs(edges,adjacent,visited,finishedVertices,n);
        }
    }
     finishedVertices.push(start);
}
void dfs2(vector<int>* edges,int start,int n,unordered_set<int> &visited,unordered_set<int>* &component){
   visited.insert(start);
    component->insert(start);
    for(int i=0;i<edges[start].size();i++){
        int adjacent = edges[start][i];
        if(visited.count(adjacent)==0){
            dfs2(edges,adjacent,n,visited,component);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<int> visited;
    stack<int> finishedVertices;
    for(int i=0;i<n;i++){
        if(visited.count(i)==0){
            dfs(edges,i,visited,finishedVertices,n);
        }
    }
    unordered_set<unordered_set<int>*>*output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(!finishedVertices.empty()){
        int element = finishedVertices.top();
        finishedVertices.pop();
        if(visited.count(element)!=0){
            continue;
        }
        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT,element,n,visited,component);
        output->insert(component);
    }
    return output;
}
int main(){
   int n,m;
   cin>>n>>m;
   
   vector<int>* edges = new vector<int>[n];
   vector<int>* edgesT = new vector<int>[n];
   for(int i=0;i<m;i++){
       int x,y;
       cin>>x>>y;
       edges[x-1].push_back(y-1);
       edgesT[y-1].push_back(x-1);
   }
   unordered_set<unordered_set<int>*>* output = getSCC(edges,edgesT,n);
   unordered_set<unordered_set<int>*>:: iterator itr = output->begin();
   while(itr!=output->end()){
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
   delete output;
   return 0;
}

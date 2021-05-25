/*
               Name - Rindhe Sushil Samadhan
               IIT Guwahati
               
*/


/*

Given a tree T of N nodes, calculate longest path between any two nodes(also known as diameter of tree).

*/



#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10001];
int f[10001], g[10001];
int diameter = 0;
void dfs(int v, int pv){
    vector<int> fvalues;
    
    for(int i=0;i<arr[v].size();i++){
        
        if(arr[v][i] == pv){
            continue;
        }
        
        dfs(arr[v][i], v);
        fvalues.push_back(f[arr[v][i]]);
    }
    
    sort(fvalues.begin(), fvalues.end());
   
    if(!fvalues.empty()){
        f[v] = 1 + fvalues.back();
    }
    
    if(fvalues.size()>1){
        g[v] = 2 + fvalues.back() + fvalues[fvalues.size()-2];
    }
    
    diameter = max(diameter, max(f[v], g[v]));
    
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++){
            arr[i].clear();
            f[i] = 0;
            g[i] = 0;
        }
        
        for(int i=0;i<n-1;i++){
            int x, y;
            cin>>x>>y;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        
        dfs(0, -1);
        
        cout<<diameter<<endl;
    }
    return 0;
    
}

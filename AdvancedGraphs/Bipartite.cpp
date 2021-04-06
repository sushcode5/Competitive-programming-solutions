
            //    Name - Rindhe Sushil Samadhan
            //    IIT Guwahati



// Given a connected graph with n vertices and m edges. Check whether it is Bipartite or not. 


#include<bits/stdc++.h>
using namespace std;
bool bipartite(vector<int>*adj,int n){
    if(n==0){
        return true;
    }
    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);
    while(pending.size()>0){
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current) > 0 ? 0 : 1;
        for(int i=0;i<adj[current].size();i++){
            int neighbour = adj[current].at(i);
            if(sets[0].count(neighbour)==0 && sets[1].count(neighbour)==0){
                sets[1-currentSet].insert(neighbour);
                pending.push_back(neighbour);
            }
            else if(sets[currentSet].count(neighbour)>0){
                return false;
            }
        }
        
    }
    return true;
}
int main(){
    while(true){
        int n,m;
        cin>>n;
        if(n==0){
            break;
        }
        cin>>m;
        vector<int>* adj = new vector<int>[n];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            
        }
        bool ans =bipartite(adj,n);
        if(ans){
            cout<<"Bicolorable"<<endl;
        }
        else{
            cout<<"Not BiColorable"<<endl;
        }
        
    }
    return 0;
}

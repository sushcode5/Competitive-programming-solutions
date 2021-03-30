/*      
            Name - Rindhe Sushil Samadhan 
            IIT Guwahati
*/

/*

Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.

Output Format :

Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.

Constraints :

0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1

Sample Input 1:

4 2
0 1
2 3

Sample Output 1:

0 1 
2 3 

Sample Input 2:

4 3
0 1
1 3 
0 3

Sample Output 2:

0 1 3 
2




*/



#include <bits/stdc++.h>
using namespace std;
vector<int> DFS(int**edges,int n,int start,vector<int>smallans,bool* visited){
    visited[start]=true;
    smallans.push_back(start);
    for(int i=0;i<n;i++){
        if(edges[start][i] && !visited[i]){
           smallans= DFS(edges,n,i,smallans,visited);
        }
    }
    
   return smallans;
}
vector<vector<int>> connectedComp(int**edges,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<vector<int>> temp;
   
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> smallans;
            smallans=DFS(edges,n,i,smallans,visited);
            temp.push_back(smallans);
        }
    }
    return temp;
}
int main() {
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a, b;
        cin >>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
   
    vector<vector<int>> output = connectedComp(edges,n);
    int len=output.size();
   for(int i=0;i<len;i++){
       sort(output[i].begin(),output[i].end());
   }
    for(int i=0;i<len;i++){
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
        
    return 0;
}

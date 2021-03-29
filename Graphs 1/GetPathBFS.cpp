/*

                     Name - Rindhe Sushil Samadhan
                     IIT Guwahati.

*/



/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :

Print the path from v1 to v2 in reverse order.

Constraints :

2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second

Sample Input 1 :

4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :

3 0 1

*/

#include<bits/stdc++.h>
using namespace std;
void findPath(int**edges,int n,int start,int end,bool* visited,unordered_map<int,int>&m){
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node]=true;
        if(node==end){
            return;
        }
        for(int i=0;i<n;i++){
            if(edges[node][i]==1 && !visited[i]){
                q.push(i);
                if(m.count(i)==0){
                    m[i]=node;
                }
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    int**edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    int start,end;
    cin>>start>>end;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    unordered_map<int,int> m;
    findPath(edges,n,start,end,visited,m);
  
    if(visited[end]){
        int temp=end;
        while(temp!=start){
            cout<<temp<<" ";
            temp=m[temp];
        }
        cout<<temp<<endl;
    }
    
    return 0;
}

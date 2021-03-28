/*
          Name - Rindhe Sushil Samadhan
          IIT Guwahati
*/





/*
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:

1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well

Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains space separated two integers, that denote that there exists an edge between vertex a and b.

Output Format :

Print the BFS Traversal, as described in the task.

Constraints :

0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:

4 4
0 1
0 3
1 2
2 3

Sample Output 1:

0 1 3 2

*/







#include<bits/stdc++.h>
using namespace std;
void printBFS(int**edges,int e,int n,int sv,bool* Visited){
    
    //create queue for pending vertices
    std::queue<int>pendingVertices;
    pendingVertices.push(sv);
    Visited[sv]=true;
    while(!pendingVertices.empty()){
        int currIndex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currIndex<<" ";
        for(int i=0;i<n;i++){
            if(currIndex==i){
                continue;
            }
            if(edges[currIndex][i]==1 && !Visited[i]){
                pendingVertices.push(i);
                Visited[i]=true;
            }
        }
    }
}
int main(){
   
    int n;
    int e;
    cin>>n>>e;
    
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    bool* Visited = new bool[n];
    for(int i=0;i<n;i++){
        Visited[i]=false;
    }
    //print BFS
    for(int i=0;i<n;i++){
        if(!Visited[i]){
             printBFS(edges,e,n,i,Visited);
        }
    }
     
    for(int i=0;i<n;i++){
        delete[] edges[i];
    }
    delete [] edges;
     delete[]Visited;
    return 0;
}

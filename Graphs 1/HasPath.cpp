 /*          Name - Rindhe Sushil Samadhan
             IIT Guwahati
            
            
*/

/*

Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.

Output Format :

The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :

0 <= V <= 1000
0 <= E <= 1000
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

true

Sample Input 2 :

6 3
5 3
0 1
3 4
0 3

Sample Output 2 :

false

*/

#include <bits/stdc++.h>
using namespace std;
bool checkPath(int**edges,int n,int sv,int ev,bool*Visited){
    if(sv==ev){
        return true;
    }
    int ans;
    std::queue<int> pendingQueue;
    pendingQueue.push(sv);
    Visited[sv]=true;
    while(!pendingQueue.empty()){
        int currIndex = pendingQueue.front();
        pendingQueue.pop();
        for(int i=0;i<n;i++){
            if(edges[currIndex][i]==1 && !Visited[i]){
                ans= checkPath(edges,n,i,ev,Visited);
            }
            if(ans==true){
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n,e;
    cin>>n>>e;
    int** edges= new int*[n];
    for(int i=0;i<n;i++){
        edges[i]= new int[n];
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
    int v1,v2;
    cin>>v1>>v2;
    bool* Visited = new bool[n];
    for(int i=0;i<n;i++){
        Visited[i]=false;
    }
    
   bool ans= checkPath(edges,n,v1,v2,Visited);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}

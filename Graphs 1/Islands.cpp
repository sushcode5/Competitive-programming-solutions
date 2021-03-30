/*
                 Name - Rindhe Sushil Samadhan
                 IIT Guwahati
*/
/*

An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 

Output Format :

Print the count the number of connected groups of islands

Constraints :

0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:

5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:

1 

*/




#include <iostream>
using namespace std;
void DFS(int**edges,int n,int start,bool*visited){
    visited[start]=true;
    for(int i=0;i<n;i++){
        if(edges[start][i] && !visited[i]){
            DFS(edges,n,i,visited);
        }
    }
    return;
}
int getCount(int** edges,int n){
    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(edges,n,i,visited);
            count++;
        }
    }
    return count;
}
int main() {
    int n,e;
    cin>>n>>e;
    int**edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
    }
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    
    
    int count= getCount(edges,n);
    cout<<count<<endl;
    return 0;
}

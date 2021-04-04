/*
              Name - Rindhe Sushil Samadhan
              IIT Guwahati

*/

/*

You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2

*/




#include<bits/stdc++.h>
using namespace std;
long long factorial(int n)
{
    return (n==1 || n==0) ? 1: n * factorial(n - 1)%(1000000007); 
}
bool valid(int x,int y,int n,int m){
    return (x>=0 && y>=0 && x<n && y<m);
}
long long connectedHorses(int**edges,int n,int m,int x,int y,bool**visited){
    visited[x][y]=true;
    int ans=1;
    int dxdy[8][2] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};   
    for(int i=0;i<8;i++){
        int newX = x +dxdy[i][0];
        int newY = y + dxdy[i][1];
        if(valid(newX,newY,n,m) && !visited[newX][newY] &&edges[newX][newY]==1){
            ans=ans+connectedHorses(edges,n,m,newX,newY,visited);
        }
    }
    return ans;
}
int main()
{
	int t;
    cin>>t;
    while(t--){
        
        long long ans = 1;
        int n,m, q;
        cin>>n>>m>>q;
        
        int** edges = new int*[n];
        for(int i=0;i<n;i++){
            edges[i]=new int[m];
            for(int j=0;j<m;j++){
                edges[i][j]=0;
            }
        }
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            edges[x-1][y-1]=1;
        }
        bool** visited = new bool*[n];
        for(int i=0;i<n;i++){
            visited[i]=new bool[m];
            for(int j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
       
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(edges[i][j]==1 && !visited[i][j]){
                    
                    long long val=connectedHorses(edges,n,m,i,j,visited);
                    ans=ans*factorial(val)%(1000000007);
                }
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            delete[] edges[i];
        }
        delete[]edges;
        for(int i=0;i<n;i++){
            delete[]visited[i];
        }
        delete[]visited;
    }
    return 0;
}

/*             Name - Rindhe Sushil Samadhan
               IIT Guwahati
               
*/


/*

Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :

The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :

Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :

1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:

2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:

1


*/



#include<bits/stdc++.h>
using namespace std;

bool graph(vector<vector<char>>&board, string name,int n,int m,int i,int j,bool**visited,int stringIndex){
    visited[i][j]=true;
    stringIndex++;
    if(stringIndex==11){
        return true;
    }
        //left
         if(j!=0 && board[i][j-1]==name[stringIndex] && !visited[i][j-1]){
             bool ans= graph(board,name,n,m,i,j-1,visited,stringIndex);
             if(ans)
                 return true;
             else{
                 visited[i][j-1]=false;
                 
             }
         }
        //right
        if(j!=m-1 && board[i][j+1]== name[stringIndex] && !visited[i][j+1]){
            bool ans= graph(board,name,n,m,i,j+1,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i][j+1]=false;
                
             }
        }
        //bottom
        if(i!=n-1 && board[i+1][j]==name[stringIndex] && !visited[i+1][j]) {
            bool ans= graph(board,name,n,m,i+1,j,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i+1][j]=false;
                 
             }
        }       
        //up
        if(i!=0 && board[i-1][j]==name[stringIndex] && !visited[i-1][j]){
           bool ans = graph(board,name,n,m,i-1,j,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i-1][j]=false;
                 
             }
        }
        //bottomleft
        if(i!=n-1 && j!=0 && board[i+1][j-1]==name[stringIndex] && !visited[i+1][j-1]){
            bool ans= graph(board,name,n,m,i+1,j-1,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i+1][j-1]=false;
                 
                 
             }
        }
        //bottomright
        if(i!=n-1 && j!=m-1 && board[i+1][j+1]==name[stringIndex] && !visited[i+1][j+1]){
            bool ans= graph(board,name,n,m,i+1,j+1,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i+1][j+1]=false;
                 
             }
        }
        //upleft
        if(i!=0 && j!=0 && board[i-1][j-1]==name[stringIndex] && !visited[i-1][j-1]){
            bool ans= graph(board,name,n,m,i-1,j-1,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i-1][j-1]=false;
                 
             }
        }
        //upright
        if(i!=0 && j!=m-1 && board[i-1][j+1]==name[stringIndex] && !visited[i-1][j+1]){
           bool ans= graph(board,name,n,m,i-1,j+1,visited,stringIndex);
            if(ans)
                 return true;
             else{
                 visited[i-1][j+1]=false;
                 
                
             }
        }
   
    return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    string name = "CODINGNINJA";
    bool**visited=new bool*[n];
    
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
                bool ans=graph(board,name,n,m,i,j,visited,0);
                if(ans){
                    return true;
                }
                else{
                    board[i][j]=false;
                }
            }
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}

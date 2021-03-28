/*
          Name - Rindhe Sushil Samadhan
          IIT Guwahati
*/


/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-

Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

Input:

First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:

1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9

Note:-
indexing starts from 1.
Sample Input

6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6

Sample Output

2
2
4

*/


#include<bits/stdc++.h>
using namespace std;
struct Node{
    int oddCount;
    int evenCount;
};
void Create(Node*tree,int* arr,int start,int end,int treeNode){
    if(start==end){
        if(arr[start]%2==0){
            tree[treeNode].oddCount=0;
             tree[treeNode].evenCount=1;
            return;
        }
        else{
            tree[treeNode].oddCount=1;
             tree[treeNode].evenCount=0;
            return;
        }
    }
    int mid=(start+end)/2;
    Create(tree,arr,start,mid,2*treeNode);
    Create(tree,arr,mid+1,end,2*treeNode+1);
    
    tree[treeNode].oddCount = tree[2*treeNode].oddCount+tree[2*treeNode+1].oddCount;
    tree[treeNode].evenCount = tree[2*treeNode].evenCount+tree[2*treeNode+1].evenCount;
    return;
}
Node Query(Node*tree,int start,int end,int left,int right,int treeNode){
   
   
    
    //completely outside
    if(start>right || end<left){
        Node temp;
        temp.oddCount=0;
        temp.evenCount=0;
        return temp;
    }
    //completely inside
    if(start>=left && end<=right){
       
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    if(mid>=right){
      return Query(tree,start,mid,left,right,2*treeNode);
    }
    if(mid<left){
        return Query(tree,mid+1,end,left,right,2*treeNode+1);
    }
    Node ans1 = Query(tree,start,mid,left,right,2*treeNode);
    Node ans2 = Query(tree,mid+1,end,left,right,2*treeNode+1);
    Node ans;
    ans.oddCount=ans1.oddCount+ans2.oddCount;
    ans.evenCount=ans1.evenCount+ans2.evenCount;
    return ans;
    
}
void Update(Node*tree,int*arr,int start,int end,int idx,int val,int treeNode){
    if(start==end){
       if(val%2==0){
           tree[treeNode].evenCount=1;
           tree[treeNode].oddCount=0;
           return;
       }
        else{
            tree[treeNode].evenCount=0;
           tree[treeNode].oddCount=1;
           return;
        }
        
    }
    int mid = (start+end)/2;
    if(mid>=idx){
        Update(tree,arr,start,mid,idx,val,2*treeNode);
    }
    else{
        Update(tree,arr,mid+1,end,idx,val,2*treeNode+1);
    }
    tree[treeNode].oddCount=tree[2*treeNode].oddCount + tree[2*treeNode+1].oddCount;
    tree[treeNode].evenCount=tree[2*treeNode].evenCount + tree[2*treeNode+1].evenCount;
    return;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node*tree=new Node[4*n];
    Create(tree,arr,0,n-1,1);
   
    
    int m;
    cin>>m;
    while(m--){
        int num,x,y;
        cin>>num>>x>>y;
        
        if(num==1){
            Node ans=Query(tree,0,n-1,x-1,y-1,1);
            cout<<ans.evenCount<<endl;
        }
        else if(num==2){
            Node ans=Query(tree,0,n-1,x-1,y-1,1);
            cout<<ans.oddCount<<endl;
        }
        else{
            Update(tree,arr,0,n-1,x-1,y,1);
        }
    }
    return 0;
}

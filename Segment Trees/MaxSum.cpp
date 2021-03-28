/*
      Name - Rindhe Sushil Samadhan
      IIT Guwahati

*/

/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input

The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.

Output

Your program should output the results of the M queries, one 
query per line.

Sample Input:

3 
-1 2 3 
1
1 2

Sample Output:

2

*/




#include<bits/stdc++.h>
using namespace std;
struct Node{
    int maxSum;
    int Sum;
    int bestPrefixSum;
    int bestSuffixSum;
};
void Create(Node* tree,int* arr, int start, int end, int treeIndex){
    if(start==end){
        tree[treeIndex].maxSum=arr[start];
        tree[treeIndex].Sum=arr[start];
        tree[treeIndex].bestSuffixSum=arr[start];
        tree[treeIndex].bestPrefixSum=arr[start];
        return;
    }
    
    int mid = (start+end)/2;
    Create(tree,arr,start,mid,2*treeIndex);
    Create(tree,arr,mid+1,end,2*treeIndex+1);
    Node left = tree[2*treeIndex];
    Node right = tree[2*treeIndex+1];
    
    tree[treeIndex].maxSum = max(max(left.maxSum,right.maxSum),max(left.bestSuffixSum+right.bestPrefixSum,max(left.Sum+right.bestPrefixSum,right.Sum+left.bestSuffixSum)));   
    tree[treeIndex].Sum = left.Sum + right.Sum;
    tree[treeIndex].bestPrefixSum = max(left.bestPrefixSum,left.Sum+right.bestPrefixSum);
    tree[treeIndex].bestSuffixSum = max(right.bestSuffixSum,right.Sum+left.bestSuffixSum);
    return;
}
Node query(Node* tree,int start,int end,int left,int right,int treeIndex){
    
    //completely outside
    if(end<left || start>right){
        Node temp;
        temp.maxSum = INT_MIN;
        temp.Sum = INT_MIN;
        temp.bestPrefixSum = INT_MIN;
        temp.bestSuffixSum = INT_MIN;
        return temp;
    }
    
    //completely inside
    if(start>=left && end<=right){
        Node temp;
        temp.maxSum = tree[treeIndex].maxSum;
        temp.Sum = tree[treeIndex].Sum;
        temp.bestPrefixSum = tree[treeIndex].bestPrefixSum;
        temp.bestSuffixSum = tree[treeIndex].bestSuffixSum;
        return temp;
    }
    //partially inside and outside
    int mid = (start+end)/2;
    if(right<=mid){
        return query(tree,start,mid,left,right,2*treeIndex);
    }
    if(left>mid){
        return query(tree,mid+1,end,left,right,2*treeIndex+1);
    }
    Node ans1 = query(tree,start,mid,left,right,2*treeIndex);
    Node ans2 = query(tree,mid+1,end,left,right,2*treeIndex+1);
    Node ans;
    ans.maxSum = max(max(ans1.maxSum,ans2.maxSum),max(ans1.bestSuffixSum+ans2.bestPrefixSum,max(ans1.Sum+ans2.bestPrefixSum,ans2.Sum+ans1.bestSuffixSum)));
    ans.Sum =  ans1.Sum + ans2.Sum;
    ans.bestPrefixSum = max(ans1.bestPrefixSum,ans1.Sum+ans2.bestPrefixSum);
    ans.bestSuffixSum = max(ans2.bestSuffixSum,ans2.Sum+ans1.bestSuffixSum);
    return ans;
}
int main() {
    int n;
    cin>>n;
    
    int *arr = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    Node* tree = new Node[4*n];
    Create(tree,arr,1,n,1);
    int m;
    cin>>m;
    while(m--){
        int xi,yi;
        cin>>xi>>yi;
       Node ans= query(tree,1,n,xi,yi,1);
       cout<<ans.maxSum<<endl;
        
    }
    return 0;
}

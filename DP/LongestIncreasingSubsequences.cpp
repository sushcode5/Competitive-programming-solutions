/*
          Name - Rindhe Sushil Samadhan
          IIT Guwahati
          
*/


// Time Complexity - O(N^2)
#include <bits/stdc++.h>
using namespace std;
int n;
int lis(vector<int> &input, vector<int> &output){
    vector<int> d(n,1);
    vector<int> p(n,-1);
    
    for(int i=0;i<n;i++){
        for(int j= i-1; j>=0; j--){
            if(input[j] < input[i] && d[i] < d[j]+1){
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }
    
    int ans = d[0];
    int pos = 0;
    
    for(int i=1;i<n;i++){
        if(d[i] > ans){
            ans = d[i];
            pos = i;
        }
    }
    
    while(pos != -1){
        output.push_back(input[pos]);
        pos = p[pos];
    }
    reverse(output.begin(), output.end());
    return ans;
    
}
int main(){
    vector<int> input;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        input.push_back(num);
    }
    
    vector<int> output;
   
    int length = lis(input, output);
  
    // print length of longest increasing subsequences
    cout<<length<<endl;
    
    // print longest increasing subsequences
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
}






// Time Complexity - O(nlogn)


#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n, int* &p)
{
    int* d = new int[n+1];
    const int INF = 1e9;
    for(int i=0;i<=n;i++){
        d[i] = INF;
        p[i] = -1;
    }
    d[0] = -INF;
    
    for(int i=0;i<n;i++){
        int j = upper_bound(d, d+n+1, arr[i]) - d;
            if(d[j-1] < arr[i] && arr[i] < d[j]){
                d[j] = arr[i]; 
                p[j] = arr[i];
        }
    }
    
    int ans = 0;
    for(int i=0;i<=n;i++){
        if(d[i] < INF){
            ans = i;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* p = new int[n+1];
          
    // print length of longest increasing subsequences
    cout<<longestIncreasingSubsequence(arr,n,p)<<endl;
    
    // print longest increasing subsequences
    for(int i=0;i<=n;i++){
        if(p[i]== -1){
            continue;
        }
        cout<<p[i]<<" ";
    }
    return 0;
}










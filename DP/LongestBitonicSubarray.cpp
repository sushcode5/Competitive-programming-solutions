/*
         Name - Rindhe Sushil Samadhan
         IIT Guwahati
         
*/


// Time Complexity - O(n^2)

#include<bits/stdc++.h>
using namespace std;
int largestBitonicSubsequences(int* arr, int n){
    int* lis = new int[n];
    int* lds = new int[n];
    
    for(int i=0;i<n;i++){
        lis[i] = 1;
        lds[i] = 1;
    }
    
    // first calculate lis till index i
    
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i] > arr[j] && lis[j]+1 > lis[i]){
                lis[i] = lis[j] + 1;
            }
        }
    }
    
    //now calculate lds starting from index i
    
    for(int i = n-1;i>=0;i--){
        for(int j= i+1; j<n;j++){
            if(arr[i] > arr[j] && lds[j]+1 > lds[i]){
                lds[i] = lds[j] + 1;
            }
        }
    }
    
    int res = lis[0] + lds[0] - 1;
    
    for(int i=0;i<n;i++){
        res = max(res, lis[i] + lds[i] - 1);
    }
    
    delete[] lis;
    delete[] lds;
    
    return res;
}
int main(){
    int n;
    cin>>n;
    
    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int answer = largestBitonicSubsequences(arr,n);
    
    cout<<answer<<endl;
    
    delete []arr;
    
    return 0;
}

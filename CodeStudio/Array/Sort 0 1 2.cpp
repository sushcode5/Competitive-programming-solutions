/*
           Name - Rindhe Sushil Samadhan
           IIT Guwahati
*/


//BrutForce Approach - Sort all of them
// Time Complexity - O(NlogN)

#include<bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
    sort(arr, arr+n);
}




// We can improved time complexity
//count numbers of zeros, ones and twos in array and then arrange.
//Time Complexity - O(N)

#include<bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeros++;
        }
        else if(arr[i]==1){
            ones++;
        }
        else{
            twos++;
        }
    }
    for(int i=0;i<n;i++){
        if(i<zeros){
            arr[i]=0;
        }
        else if(i>=zeros && i<ones+zeros){
            arr[i]=1;
        }
        else{
            arr[i]=2;
        }
    }
}






//Best Approach
//Time Complexity O(N)

#include<bits/stdc++.h>
using namespace std;
void sort012(int *arr, int n)
{
   int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


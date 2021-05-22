/*
          Name - Rindhe Sushil Samadhan
          IIT Guwahati
          
 */


/*

You have been given an integer array/list (ARR) of size N. You have to return an array/list PRODUCT such that PRODUCT[i] is equal to the product of all the elements of ARR except ARR[i]
 Note:
Each product can cross the integer limits, so we should take modulo of the operation. 

Take MOD = 10^9 + 7 to always stay in the limits.
Input Format :
The first line contains an integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output Format :
For each test case, print the elements of the 'PRODUCT' array separated by a single space. 

Output for every test case will be printed in a separate line.
Important Note:
You are required to return the product array and no need to print the result explicitly. It has already been taken care of.
Constraints :
1 <= t <= 100
0 <= N <= 10^5
0 <= ARR[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
3
1 2 3
3
5 2 2
Sample Output 1 :
6 3 2
4 10 10
Sample Input 2 :
2
1
100
2
1 2
Sample Output 2 :
1
2 1


*/
 
 //Optimised Solution 
 // Time Complexity - O(N)
 // Space Complexity - O(N)
 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int multiply(int a, int b){
    long long res = (a % mod);
    res *= (b % mod);
    res = (res % mod);
    return int(res);
}
int* getPrefixArray(int*arr, int n){
    int product = 1L;
    
    int* prefixArray = new int[n];
    
    for(int i=0;i<n;i++){
        prefixArray[i] = product;
        product = multiply(product,arr[i]);
    }
    return prefixArray;
}
int* getSuffixArray(int*arr,int n){
    int product = 1L;
    
    int* suffixArray = new int[n];
    
    for(int i=n-1;i>=0;i--){
        suffixArray[i] = product;
        product = multiply(product,arr[i]);    
    }
    return suffixArray;
}
int *getProductArrayExceptSelf(int *arr, int n)
{
    int* output = new int[n];
    
    int* prefixArray = getPrefixArray(arr,n);
    int* suffixArray = getSuffixArray(arr,n);
    
    for(int i=0;i<n;i++){
       output[i] = multiply(prefixArray[i], suffixArray[i]);
    }
    
    return output;
}
 
 
 
 
 

/*
         Name - Rindhe Sushil Samadhan
         IIT Guwahati
         
*/

/*
Problem Statement
You are given two arrays of integers. Let's call the first array A and the second array B. For every element of array, A find the number of elements in array B which are smaller than or equal to that element.
For Example:
A=[2,3,0] , B=[5,1]
For the first index, A[0]=2
In array B only 1 is less than 2. Therefore the answer for the first index is 1.
For the second index, A[1]=3
In array B only 1 is less than 3. Therefore the answer for the second index is also 1.
For the third index, A[2]=0
Both the elements of array B are greater than 0. 
Therefore the answer for the third index is 0.
Hence, the final answer is [1,1,0] in this case.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases.
Then the test case follows.
The first line of each test case contains an integer ‘N’ denoting the number of elements in the array A. 
The second line of each test case contains ‘N’ space-separated integers denoting the elements of array A.
The third line of each test case contains an integer ‘M’ denoting the number of elements in the array B. 
The second line of each test case contains ‘M' space-separated integers denoting the elements of array B.
Output Format:
For each test case, print N space-separated integers represent the number of elements in array B that are smaller than the corresponding element in array A.
Constraints:
1 <= T <= 10
1 <= N,M <= 10^4
-10^9 <= A[i] , B[i]<= 10^9

Time limit: 1 second
Note:
Do not print anything, just return an array of integers denoting the number of elements in array B that are smaller than the corresponding element in an element of array A.
Sample Input 1:
1
5
5 4 3 2 1
2
3 4
Sample Output 1:
2 2 1 0 0
Explanation Of Sample Input 1 :
For the first index, A[0]=5
Both the elements of Array B are less than 5. Therefore the answer for the first index is 2.
For the second index, A[1]=4
In array B, one element is smaller than 4 and one element is equal to 4. Therefore the answer for the second index is also 2.
For the third index, A[2]=3
In array B only one element is equal to 3. Therefore the answer for the third index is 1.
For the fourth index, A[3]=2
Both the elements of Array B are greater than 2. Therefore the answer for the fourth index is 0.
For the fifth index, A[4]=1
Both the elements of Array B are greater than 1. Therefore the answer for the last index is 0.
Hence, the final answer is [2,2,1,0,0] in this case.

*/



// BrutForce Solution

//Time Complexity - O(n*m) where n and m are size of two arrays.

vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    vector<int> result;
   for(int i=0;i<n;i++){
       int count = 0;
       for(int j=0;j<m;j++){
           if(b[j]<= a[i]){
               count++;
           }
       }
       result.push_back(count);
   }
    return result;
}

// Optimal Solution 
// Time Complexity - O(nlogm)

#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int* b,int low, int high, int X){
    if(high<low){
        return 0;
    }
    int mid = low + (high-low)/2;
    
    if(b[mid]>X){
        return BinarySearch(b,low,mid-1,X);
    }
    else {
        return mid-low+1 + BinarySearch(b,mid+1,high,X);
    }
    
}
vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) {
    vector<int> result;
    // Sort array b
    //Don't sort array a, because it will affect sequence of result.
    sort(b,b+m);
    
   for(int i=0;i<n;i++){
       // perform binary search for element of array a.
       int count = BinarySearch(b,0,m-1,a[i]);
       result.push_back(count);
   }
    return result;
}












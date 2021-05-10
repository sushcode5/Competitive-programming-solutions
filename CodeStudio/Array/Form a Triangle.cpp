/* 
         Name - Rindhe Sushil Samadhan
         IIT Guwahati
*/



/*
Problem Statement
You are given an integer of array/list of length ‘N’, you are supposed to return true if it is possible to construct at least one non-degenerate triangle using values of array/list as sides of the triangle, otherwise, return false.
Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array.

The second line contains ‘N’ single space-separated integers denoting the elements of the array/list.
Output Format:
For each test case, print in a new line “YES”(without quotes) if it is possible to form a non-degenerate triangle, otherwise print “NO”(without quotes).
Note:
You don’t need to print anything; It has already been taken care of.
Constraints:
1 <= T <= 100
3 <= N <= 10^3
0 <= ARR[i] <= 10^9

Where ‘T’ denotes the number of test cases, ‘N’ denotes the number of elements in the array and ARR[i] denotes the elements of the array.

Time Limit: 1 sec
Sample Input 1 :
2
5
4 2 1 3 2
5
5 2 7 3 15
Sample Output 1:
YES
YES
Explanation Of Sample Input 1:
In the first test case, if we choose the sides as { 2,3,4} or {2,2,1} or {2,2,3} then it is possible to form a non-degenerate triangle.

In the second test case, if we choose sides as {5,3,7}, then it is possible to form a non-degenerate triangle.
Sample Input 2:
2
5
12 3 7 4 28
4
7 12 9 20
Sample Output 2:
NO
YES
Explanation Of Sample Input 2:
In the first test case, there is no possible way to choose three elements such that they will form the sides of a triangle.
In the second test case, if we choose the sides as {7,12,9} or {12,9,20}, then it is possible to form a non-degenerate triangle


*/




// BrutForce Approach
// Check for each triplet in the array

bool isTriangle(int a, int b, int c){
    return (a+b>c && b+c>a && a+c>b);
}
bool possibleToMakeTriangle(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(isTriangle(arr[i],arr[j],arr[k])){
                    return true;
                }
            }
        }
    }
    return false;
}



// Optimised Approach
// Using Sorting

#include<bits/stdc++.h>
using namespace std;
bool possibleToMakeTriangle(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        if(arr[i]+arr[i+1] > arr[i+2]){
            return true;
        }
    }
   return false; 
}


/* 
              Name - Rindhe Sushil Samadhan
              IIT Guwahati

*/


/*

Problem Statement
Aahad and Harshit always have fun by solving problems. Harshit took a sorted array and rotated it clockwise by an unknown amount. For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating a sorted array, Aahad needs to answer Q queries asked by Harshit, each of them is described by one integer Q[i] which Harshit wanted him to search in the array. For each query, if he founds it, he had to shout the index of the number, otherwise, he had to shout -1.
Input Format:
The first line of input contains the size of the array: N

The second line contains N single space-separated integers: A[i].

The third line of input contains the number of queries: Q

The next Q lines of input contain: the number which Harshit wants Aahad to search: Q[i]
Output Format:
For each test case, print the index of the number if found, otherwise -1.

Output for every test case will be printed in a separate line.
Note:
You are not required to explicitly print the expected output, just return it and printing has already been taken care of.
Constraints:
1 <= N <= 10^6
-10^9 <= A[i] <= 10^9
1 <= Q <= 500
-10^9 <= Q[i] <= 10^9

Time Limit: 1sec
Sample Input 1:
4
2 5 -3 0
2
5
0
Sample Output 1:
1
3
Sample Input 2:
5
100 -2 6 10 11
2
100
6
Sample Output 2:
0
2

*/




#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int*arr,int low,int high,int key){
    int mid = low + (high-low)/2;
    if(high<low){
        return -1;
    }
    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return BinarySearch(arr,low,mid-1,key);
    else
        return BinarySearch(arr,mid+1,high,key);    
}
int findIndex(int*arr,int low, int high){
    if(high<low){
        return -1;
    }
    int mid = low + (high-low)/2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findIndex(arr, low, mid - 1);
    return findIndex(arr, mid + 1, high);
}
int search(int* arr, int n, int key)
{
    int d = findIndex(arr,0,n-1);
    if(d== -1){
        BinarySearch(arr,0,n-1,key);
    }
    else{
        
    
   if(key>=arr[0])
       return BinarySearch(arr,0,d,key);
    else
        return BinarySearch(arr,d+1,n-1,key);
    }
}
  

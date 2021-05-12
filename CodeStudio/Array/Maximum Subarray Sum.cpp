/* 
              Name - Rindhe Sushil Samadhan
              IIT Guwahati
              
 
 */



/*
 
Problem Statement
You are given an array (ARR) of length N, consisting of integers. You have to find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning, and 0 or more integers from the end of an array.
Note:
The sum of an empty subarray is 0.
Input Format:
The first line of input contains an integer N, representing the length of the array.

The second line of input contains N single space-separated integers, denoting the elements of the array.
Output Format:
In the only output line, output the maximum subarray sum.
Constraints:
1 <= N <= 10^6
-10^6 <= A[i] <= 10^6

where N is the length of the array.
A[i] represents the numbers present in the array.

Time limit: 1sec
Sample Input 1:
9
1 2 7 -4 3 2 -10 9 1
Sample Output 1:
11
Explanation For Sample 1:
The subarray yielding maximum sum is [1, 2, 7, -4, 3, 2].
Sample Input 2:
6
10 20 -30 40 -50 60
Sample Input 2:
60


*/





long long maxSubarraySum(int arr[], int n)
{
    long long max_sum = 0;
    long long curr_sum = 0;
    
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        if(curr_sum > max_sum){
            max_sum = curr_sum;
        }
    }
    return max_sum;
}

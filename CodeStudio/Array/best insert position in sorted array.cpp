/*       
              Name - Rindhe Sushil Samadhan
              IIT Guwahati
              
 */



/*   

Problem Statement
You are given a sorted array A of length N with distinct integers and a target integer M. You need to return the position of M if it existed in the array A. If it already exists in A, return that position. (0-based indexing)
For example: If the given array A is: [1, 2, 4, 7] and M = 6. We insert M=6 in the array and get A as: [1, 2, 4, 6, 7]. The position of 6 is 3 (according to 0-based indexing)
Input Format:
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
Then the T test cases follow.
The first line of each test case contains two space-separated integers N and M, representing the length of the array and the target integer.
The second line of each test case contains N space-separated integers, Ai representing the given array.
Output Format:
For each test case, print the position of M in the final array, on a new line.
Constraints:
1 ≤ T ≤ 10
0 ≤ N ≤ 10^5
1 ≤ M ≤ 10^9
1 ≤ Ai ≤ 10^9
Time Limit : 1 sec

Note:
Try to solve the problem in O(log N)
The given array has distinct integers.
The given array may be empty.
You are not required to print the expected output, it has already been taken care of. Just implement the function.
Sample Input 1:
2
4 6
1 2 4 7
4 9
1 2 4 7
Sample Output 1:
3
4
Explanation Of Input 1:
The first test case is already explained in the problem statement.
The second test case, the given array A is: [1, 2, 4, 7] and M = 9. We insert M=9 in the array and get A as: [1, 2, 4, 6, 9]. The position of 9 is 4 (according to 0-based indexing)
Sample Input 2:
2
3 1
2 5 7
3 5
2 5 7
Sample Output 2
0
1
Explanation Of Input 2:
The first test case, the given array A is: [2, 5, 7] and M = 1. We insert M=1 in the array and get A as: [1, 2, 5, 7]. The position of 1 is 0 (according to 0-based indexing)
The second test case, the given array A is: [2, 5, 7] and M = 5. We insert M=5 in the array and get A as: [2, 5, 7].(since the array can have only distinct integers. The position of 5 is 1 (according to 0-based indexing)


*/









// Time Complexity - O(logN)
// Space Complexity - O(logN)


int BinarySearch(vector<int> b,int low, int high, int X){
    if(high<low){
        return 0;
    }
    int mid = low + (high-low)/2;
    
    if(b[mid]>=X){
        return BinarySearch(b,low,mid-1,X);
    }
    else {
        return mid-low+1 + BinarySearch(b,mid+1,high,X);
    }
    
}
int bestInsertPos(vector<int> arr, int n, int m)
{
    int count = BinarySearch(arr,0,n-1,m);
    
    return count;
}


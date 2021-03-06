/*
                  Name - Rindhe Sushil Samadhan
                  IIT Guwahati
                  
*/


/*

Problem Statement
You are given a matrix ‘ARR’ with ‘N’ rows and ‘M’ columns. Your task is to find the maximum sum rectangle in the matrix.
Maximum sum rectangle is a rectangle with the maximum value for the sum of integers present within its boundary, considering all the rectangles that can be formed from the elements of that matrix.
For Example
Consider following matrix:

The rectangle (1,1) to (3,3) is the rectangle with the maximum sum, i.e. 29.

Input Format
The first line of input contains an integer ‘T’ denoting the number of test cases to run. Then the test cases follow.

The first line of each test case contains two space-separated integers ‘N’ and ‘M’ denoting the number of rows and number of columns respectively.

The next ‘N’ lines contain ‘M’ space-separated integers denoting the elements of ARR.
Output Format
For each test case, print the value of the sum for the maximum sum rectangle.

Print the output of each test case in a separated line.
Note
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
 1 <= T <= 10
 1 <= M, N <= 75
 -10^5 <= ARR[i][j] <=10^5

Time Limit: 1 sec
Sample Input 1
2
1 2
-1 1
2 2
-1 1
2 2
Sample Output 1
1
4
Explanation Of Input 1
The maximum sum rectangle corresponding to the first test case is-

The maximum sum rectangle corresponding to the second test case is-

Sample Input 2
1
4 5
1 2 -1 -4 -20
-8 -3  4 2 1
3  8 10 1 3
-4 -1 1 7 -6
Sample Output 2
29

*/


// BrutForce Solution - O((N*M)^3)
// Space Complexity - O(1)

#include<bits/stdc++.h>
using namespace std;
// All squares are rectangle but all rectangles are not square.
int maxSumRectangle(vector<vector<int>>& arr, int n, int m)
{
    int left,right,top,bottom;
    int maxSum = INT_MIN;
    
   for(top = 0;top < n; top++){
      
        for(left = 0;left < m ; left++){
    
            for(bottom = top;bottom < n; bottom++){
               
                for(right = left;right < m; right++){
                    
                    int sum = 0;
                    for(int i = top; i <= bottom; i++){
                        for(int j = left; j<=right; j++){
                            sum += arr[i][j];
                        }
                    }
                    maxSum = max(sum,maxSum);
                }
            }
        }
    }
    return maxSum;
}







/*

	Time complexity: O((N * M)^2)
	Space complexity: O(N * M)
	
	where N is the number of rows and M is the number of columns in the matrix.

*/

int findSum(int top, int left, int bottom, int right, int n, int m, vector<vector<int>> &prefixSum){
   
    int sum = prefixSum[bottom][right];
    
    if(left-1>=0){
        
        sum -= prefixSum[bottom][left-1];
    }
    if(top-1>=0){
        
        sum -= prefixSum[top-1][right];
    }
    
    if( (left-1>=0) && (top-1>=0) ){
        
        sum += prefixSum[top-1][left-1];
    }
    return sum;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m){
    
    vector<vector<int>> prefixSum(n,vector<int>(m,0));
    //Row Wise Prefix Sum
    for(int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
            
            prefixSum[i][j] = arr[i][j];
            
            if(j!=0){
                
                prefixSum[i][j] += prefixSum[i][j-1];
            }
        }
    }
    
    // Col Wise Prefix Sum
    for(int j=0;j<m;j++){
        
        for(int i=0;i<n;i++){
            
            if(i!=0){
                
                prefixSum[i][j] += prefixSum[i-1][j];
            }
        }
    }
    int maxSum = INT_MIN;
    
    for(int top = 0;top < n; top++){
        
        for(int left = 0; left < m; left++){
            
            for(int bottom = top; bottom < n; bottom++){
                
                for(int right = left; right < m; right++){
                    
                    int sum = findSum(top, left, bottom, right, n, m, prefixSum);
                    
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
    return maxSum;
}








// Time Complexity - O(N*(M^2))
// Space Complexity - O(N)


#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        
        maxSum = max(sum, maxSum);
        
        if(sum < 0){
            sum = 0;
        }
    
    }
    return maxSum;
}
int maxSumRectangle(vector<vector<int>>& arr, int n, int m){
    
    int maxSum  = INT_MIN;
    
    int temp[n];
    
    for(int left = 0;left < m; left++){
        for(int i=0;i<n;i++){
            temp[i] = 0;
        }
        
        for(int right = left; right < m; right++){
            for(int i=0;i<n;i++){
                temp[i] += arr[i][right];
            }
            
            int sum = kadane(temp, n);
            
            maxSum = max(sum, maxSum);
        }
    }
    
    return maxSum;
}

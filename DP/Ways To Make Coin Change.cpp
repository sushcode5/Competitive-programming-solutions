/*

       Name - Rindhe Sushil Samadhan
       IIT Guwahati

*/




// Recursion using Memoization
// Time Complexity - O(N*Value)
// Space Complexity - O(N*Value)

#include<bits/stdc++.h>
using namespace std;
long countWaysToMakeChangeHelper(int *denominations, int n, int value, vector<vector<long>> &memo){
    if(value == 0){
        return 1;
    }
    if(n==0 || value < 0){
        return 0;
    }
    
    if(memo[value][n] != -1){
        return memo[value][n];
    }
    
    long ans1 = countWaysToMakeChangeHelper(denominations, n, value - denominations[0], memo);
    long ans2 = countWaysToMakeChangeHelper(denominations+1, n-1, value, memo);
    
    memo[value][n] = ans1 + ans2;
    return memo[value][n];
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> memo(value+1, vector<long>(n+1, -1));
    return countWaysToMakeChangeHelper(denominations, n, value, memo);
}


//Iterative Solution
// Time Complexity - O(N*V)
// Space Complexity - O(V)

long countWaysToMakeChange(int *denominations, int n, int value)
{
    long dp[value+1];
    for(int i=1; i<=value;i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    
    for(int i=0;i<n;i++){
        
        for(int j=denominations[i]; j<=value; j++){
            dp[j] += dp[j - denominations[i]];
        }
    }
    return dp[value];
}


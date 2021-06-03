/*
           Name - Rindhe Sushil Samadhan
           IIT Guwahati
           
*/


/*

You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. Each time you can either climb one step or two steps. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

*/

#define mod 1000000007
void Multiply(long long A[2][2], long long M[2][2]){
   
    
    long long first = ((A[0][0]*M[0][0])%mod + (A[0][1]*M[1][0])%mod);
    
    long long second = ((A[0][0]*M[0][1])%mod + (A[0][1]*M[1][1])%mod);
    
    long long third = ((A[1][0]*M[0][0])%mod + (A[1][1]*M[1][0])%mod);
    
    long long fourth = ((A[1][0]*M[0][1])%mod + (A[1][1]*M[1][1])%mod);
    
    A[0][0] = first % mod;
    A[0][1] = second % mod;
    A[1][0] = third % mod;
    A[1][1] = fourth % mod;
}
void power(long long A[2][2], long long n){
    
    if(n==0 || n==1){
        return;
    }
    power(A,n/2);
    
    Multiply(A,A);
    
    if(n%2 == 1){
        long long M[2][2] = {{1,1},{1,0}};
        
        Multiply(A,M);
    }
}
long long fib(long long n){
    long long A[2][2] = {{1,1},{1,0}};
    power(A, n);
    return A[0][0];
}
int countDistinctWayToClimbStair(long long nStairs)
{
    return (int)fib(nStairs)%mod;
}

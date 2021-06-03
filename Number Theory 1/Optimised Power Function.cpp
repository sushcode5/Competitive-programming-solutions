/*

       Name - Rindhe Sushil Samadhan
       IIT Guwahati
       
*/


// find (a^b)
// Time Complexity - O(logN)

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int modExp(int a, int b){
    if(a==0){
        return 0;
    }
    
    if(b==0){
        return 1;
    }
    
    long ans;
    
    if(b%2 == 0){
        //b is even
        
        long smallAns = modExp(a,b/2);
        ans = (smallAns*smallAns)%mod;
    }
    else{
        // b is odd
        
        long smallAns = modExp(a,b-1);
        ans = a%mod;
        
        ans = (ans*smallAns)%mod;
    }
    
    return (int)(ans+ mod)%mod;
}

int main(){
    int a,b;
    cin>>a>>b;
    
    int res = modExp(a,b);
    
    cout<<res<<endl;
    
    return 0;
}

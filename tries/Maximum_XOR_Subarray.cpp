/*
           Name - Rindhe Sushil Samadhan
           IIT Guwahati
 
*/


/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7

*/



#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    trieNode* left;
    trieNode* right;
};

int findMaxXor(int n, trieNode* head){
    int curr_xor = 0;
    
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
       int b = (n>>i)&1;
    
        if(b==0){
            if(curr->right){
                curr_xor+=pow(2,i);
                curr=curr->right;
            }
            else{
                
                curr=curr->left;
            }
        }
        else{
            if(curr->left){
                curr_xor+=pow(2,i);
                curr=curr->left;
            }
            else{
                curr=curr->right;
            }
        }
    }
    return curr_xor;
}

void insert(int x, trieNode* head){
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        int b = (x>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr= curr->left;
        }
        else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr=curr->right;
        }
    }
    return;
}
int find_max_xor_subarray(int* arr, int n, trieNode* head){
    int max_xor = INT_MIN;
    int subarr_xor = 0;
    
    for(int i=0;i<n;i++){
        subarr_xor= (subarr_xor)^(arr[i]);
         insert(subarr_xor,head);
        
        int probable_ans =  findMaxXor(subarr_xor,head);
        
        if(probable_ans > max_xor){
            max_xor = probable_ans;
        }
        
       
        
        
        
    }
    return max_xor;
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trieNode* head = new trieNode();
    
    cout<<find_max_xor_subarray(arr,n,head)<<endl;
    return 0;
}


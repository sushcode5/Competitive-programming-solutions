/* 
            Name - Rindhe Sushil Samadhan
            College - IIT Guwahati

*/


#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    
        trieNode* left;
        trieNode* right;
};

void insert(int n,trieNode* head){
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        int b = (n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr ->left = new trieNode();
            }
            curr = curr ->left;
        }
        else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr -> right;
        }
    }
}
int findXorMax(int*arr,trieNode*head,int n){
    
    int currMax = INT_MIN;
    for(int i=0;i<n;i++){
        int val = arr[i];
        trieNode* curr = head;
        int currxor = 0;
        for(int j=31;j>=0;j--){
            int b = (val>>j)&1;
            if(b==0){
                if(curr->right){
                    currxor+=pow(2,j);
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->left){
                    currxor+=pow(2,j);
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }
                
            }
           
        }
        if(currxor>currMax){
            currMax=currxor;
            
        }
        
    }
    return currMax;
}
int main(){
    int n;
    cin>>n;
    int*arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trieNode*head = new trieNode();
    for(int i=0;i<n;i++){
        insert(arr[i],head);
    }
    cout<<findXorMax(arr,head,n)<<endl;
    delete[]arr;
    return 0;
}

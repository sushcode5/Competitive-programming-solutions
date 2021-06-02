/*
          Name - Rindhe Sushil Samadhan
          IIT Guwahati
          
*/



#include <bits/stdc++.h>
using namespace std;
int n;
int lis(vector<int> &input, vector<int> &output){
    vector<int> d(n,1);
    vector<int> p(n,-1);
    
    for(int i=0;i<n;i++){
        for(int j= i-1; j>=0; j--){
            if(input[j] < input[i] && d[i] < d[j]+1){
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }
    
    int ans = d[0];
    int pos = 0;
    
    for(int i=1;i<n;i++){
        if(d[i] > ans){
            ans = d[i];
            pos = i;
        }
    }
    
    while(pos != -1){
        output.push_back(input[pos]);
        pos = p[pos];
    }
    reverse(output.begin(), output.end());
    return ans;
    
}
int main(){
    vector<int> input;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        input.push_back(num);
    }
    
    vector<int> output;
   
    int length = lis(input, output);
  
    // print length of longest increasing subsequences
    cout<<length<<endl;
    
    // print longest increasing subsequences
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
}

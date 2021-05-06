
/* 
           Name - Rindhe Sushil Samadhan
           IIT Guwahati

*/


/*
Given two 1-dimensional arrays containing strings of lowercase alphabets, print the elements that are common in both the arrays i.e. the strings that are present in both the arrays.
Note :
An element of one array can be mapped only to one element of the array. For example :

Array 1 = {“ab”, “dc”, “ab”, “ab”}
Array 2 = {“dc”, “ab”, “ab”} 

The common elements for the above example will be “dc”, “ab” and “ab”. 
Input Format
The first line of input contains an integer 'T' representing the number of test cases. Then the test cases follow.

The first line of each test case includes two integers, N and M, representing the sizes of the both the arrays.

The second line of each test case contains N single spaced strings representing the elements of the first array.

The third line of each test case contains M single spaced strings representing the elements of the second array.
Output Format:
For each test case, the common elements of both the arrays are printed in the order in which they appear in the second array. The elements are printed in a single space separated manner. 

You do not need to print anything, it has already been taken care of. Just return the common elements in the specified order.

Print the output for each test case in a separate line.
Constraints:
1 <= T <= 10
1 <= N, M <= 10000    
1 <= S <= 10

Where N and M are the sizes of both the arrays and S is the length of the strings of the arrays. Also, the strings contain only lowercase alphabets.
Sample Input 1:
1
3 5
at bat rat
rat bar bat rat to
Sample Output 1:
rat bat
Explanation Of The Sample Input 1:
The common elements of both the arrays are “bat” and “rat”. Thus, these two elements are printed in the order in which they appear in the second array.
Sample Input 2:
2
2 2
a b
c d
2 1
coding ninjas
coding
Sample Output 2:
coding
Explanation Of Sample Input 2
There are no common elements for the first test case. For the second case, “coding” is the common element.
*/

#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    int count;
    bool isWord;
    char letter;
    trieNode** children = new trieNode*[26];
    trieNode(){
        count=0;
        letter = '\0';
        isWord = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

void insert(string s, trieNode* root){
    trieNode* curr = root;
    int i;
    for( i=0;i<s.length();i++){
        int index = s[i] - 'a';
        if(!curr->children[index]){
            curr->children[index] = new trieNode();
            curr->children[index]->letter = s[i];
        }
        curr = curr->children[index];
    }
    if(i==s.length()){
        curr->count = curr->count+1;
        curr->isWord = true;
    }
    return;
}
string query(string s,trieNode* root){
    trieNode* curr = root;
    string ans;
    for(int i=0;i<s.length();i++){
        int index = s[i] -'a';
        if(curr->children[index]){
            curr = curr->children[index];
        }else{
            ans='\0';
            return ans;
        }
    }
    if(curr->isWord == true && curr->count!=0){
        curr->count = curr->count-1;
        ans = s;
    }
    return ans;
}
vector<string> findCommonElements(string arr1[], string arr2[], int n, int m){
    trieNode* root = new trieNode();
    // insert strings of arr1 in a trie.
    for(int i=0;i<n;i++){
        insert(arr1[i],root);
    }
    
    vector<string> answer;
    string smallans;
    // Run a query for each string in arr2
    for(int i=0;i<m;i++){
       
      smallans =  query(arr2[i],root);
     
      if(smallans[0]!='\0'){
          
          answer.push_back(smallans);
      }
    }
    return answer;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string arr1[100], arr2[100];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<m;i++){
            cin>>arr2[i];
        }
        
        vector<string> result = findCommonElements(arr1,arr2,n,m);
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

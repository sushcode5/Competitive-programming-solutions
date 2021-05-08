/*
            Name - Rindhe Sushil Samadhan
            IIT Guwahati

*/


/*
Problem Statement
You are given a non-empty string S containing no spaces’ and a dictionary of non-empty strings (say the list of words). You are supposed to construct and return all possible sentences after adding spaces in the originally given string ‘S’, such that each word in a sentence exists in the given dictionary.
Note :
The same word in the dictionary can be used multiple times to make sentences.
Assume that the dictionary does not contain duplicate words.
Input format :
The first line contains an integer ‘T’ denoting the number of test cases. 
Each test case follows:
The first line contains an integer value ‘K’ which denotes the size of the dictionary.
The second line contains ‘K’ non-empty, space separated strings denoting the words of the dictionary.
The third line contains a non-empty string ‘S’.
Output format :
For each test case, print each possible sentence after adding spaces, in different lines.
The output of each test case is printed in a separate line. 
Note :
1. You do not need to print anything, it has already been taken care of. Just implement the given function.
2. The order in which the output sentences are returned does not matter.
Constraints :
1 <= T <= 10
1 <= K <= 100
1 <= | word | <= 16
1 <= | S | <= 13
where ‘T’ is the number of test cases,  ‘K’ is the length of a dictionary , | word | is the length of each word in the dictionary and | S | is the length of the string S.
Sample Input 1:
1
6
god is now no where here
godisnowherenowhere
Sample Output 1:
god is no where no where
god is no where now here
god is now here no where
god is now here now here
Explanation To Sample Input 1:
One way to make sentences is to take “god” and append a space, then take “is”  and append space, take “now” from the dictionary and take “here” as well. 
Similarly, for other sentences also, we can add space to get other possible sentences. Note that we can reuse dictionary words as “no” and “now” are used two times in the same sentence.
Sample Input 2:
1
4
god is no here
godisnowhere
Sample Output 2:
No output to be printed
Explanation To Sample Input 2:
We can not make any sentence because after making “god is no” we will be stuck with “where”. There is no way to break “where” further such that we can get any word from the dictionary.
*/



//Approach 1 - Using Trie

class trieNode{
    public:
    bool isWordComplete;
    trieNode* children[26];
    trieNode(){
        isWordComplete = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};
void insert(string s, trieNode*root){
    trieNode* curr = root;
    int i;
    for( i=0;i<s.size();i++){
        int index = s[i]-'a';
        if(!curr->children[index]){
            curr->children[index] = new trieNode();
        }
        curr= curr->children[index];
    }
    
        curr->isWordComplete =true;
    
    return;
}
void query(trieNode*root, string s,vector<string> &result,string temp,int pos){
    trieNode* curr = root;
    for(int i=pos;i<s.size();i++){
        int index = s[i]-'a';
        if(curr->children[index]==NULL){
            return;
        }
        if(curr->children[index]->isWordComplete == true){
            string lastWord = temp;
            lastWord.append(s.substr(pos,i-pos+1));
            if(i==s.size()-1){
                result.push_back(lastWord);
            }
            else{
                query(root,s,result,lastWord+ " ",i+1);
            }
        }
        curr=curr->children[index];
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    trieNode* root = new trieNode();
    for(int i=0;i<dictionary.size();i++){
        string s = dictionary[i];
        insert(s,root);
    }
    vector<string> result;
    query(root,s,result,"",0);
    return result;
}




// Approach 2 - Using Recursion


#include<bits/stdc++.h>
using namespace std;
vector<string> wordBreakHelper(string &s,unordered_set<string>&dictSet,int pos,int size){
    if(pos==size){
        return {""};
    }
    vector<string> smallAns,output;
    string word ="";
    for(int i=pos;i<size;i++){
        word.push_back(s[i]);
        if(dictSet.count(word)==0){
            continue;
        }
        smallAns = wordBreakHelper(s,dictSet,i+1,size);
        
        for(int j=0;j<smallAns.size();j++){
            if(smallAns[j].size()!=0){
                string temp=word;
                temp.append(" ");
                temp.append(smallAns[j]);
                smallAns[j]=temp;
            }
            else{
                smallAns[j]=word;
            }
        }
        for(int i=0;i<smallAns.size();i++){
            output.push_back(smallAns[i]);
        }
    }
    return output;
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    
    unordered_set<string> dictSet;
    for(int i=0;i<dictionary.size();i++){
        dictSet.insert(dictionary[i]);
    }
    
   return  wordBreakHelper(s,dictSet,0,s.size());
    
}



// Approach 3 - Using Memoisation



#include<bits/stdc++.h>
using namespace std;
vector<string> wordBreakHelper(string &s,unordered_set<string>&dictSet,int pos, map<int,vector<string>> &dp, int size){
    if(pos==size){
        return {""};
    }
    
    if (dp.find(pos) != dp.end())
    {
        return dp[pos];
    }
    vector<string> smallAns,output;
    string word ="";
    for(int i=pos;i<size;i++){
         
        word.push_back(s[i]);
        if(dictSet.count(word)==0){
            continue;
        }
        smallAns = wordBreakHelper(s,dictSet,i+1,dp,size);
        
        for(int j=0;j<smallAns.size();j++){
            if(smallAns[j].size()!=0){
                string temp=word;
                temp.append(" ");
                temp.append(smallAns[j]);
                smallAns[j]=temp;
            }
            else{
                smallAns[j]=word;
            }
        }
        for(int i=0;i<smallAns.size();i++){
            output.push_back(smallAns[i]);
        }
    }
    dp[pos] = output;
    return dp[pos];
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    
    unordered_set<string> dictSet;
    for(int i=0;i<dictionary.size();i++){
        dictSet.insert(dictionary[i]);
    }
    map<int,vector<string>> dp;
   return  wordBreakHelper(s,dictSet,0,dp,s.size());
    
}















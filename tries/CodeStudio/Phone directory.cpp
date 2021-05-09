/*
              Name - Rindhe Sushil Samadhan
              IIT Guwahati
              
*/


/*
Problem Statement
You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character.
Note :
If no suggestions are found, return an empty 2D array.
For Example :

In the above example everytime we enter a character, a few suggestions display the strings which contain the entered string as prefixes.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases.

The first line of each test case contains a single integer ‘N’ denoting the number of elements in the array/list.

The second line contains ‘N’ single space-separated strings denoting the contacts of the given array/list or contact list.

The third line contains a single string denoting the query string.
Output Format :
For each test case, for the given query string you need to print all the possible contacts or suggestions that are present in the given directory corresponding to each entered character in the given query string. If no suggestions are found then the message “No suggestions found” is printed.
Note :
You do not need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 50
1 <= N <= 100
1 <= len <= 10
ARR[i] contains lowercase English alphabets.
All the given strings contain lowercase English alphabets.

Where ‘T’ is the number of test cases.
'N' is the length of the given array/list.
‘len’ is the length of the longest string among the given strings.
And, ARR[i] denotes the i-th string in the given array/list.

Time Limit: 1 sec.
Sample Input 1 :
2
5
cod coding codding code coly
coding
2
ninjas coding
ninja
Sample Output 1 :
cod coding codding code coly
cod coding codding code coly
cod coding codding code coly
coding
coding
coding
ninjas
ninjas
ninjas
ninjas
ninjas
ninjas
Explanation To Sample Input 1 :
In the first test case, 
The suggestions for “c” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “co” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestions for “cod” is {“cod”, “coding”, “codding”, “code”, “coly”}.
The suggestion for “codi” is {“coding”}.
The suggestion for “codin” is {“coding”}.
The suggestion for “coding” is {“coding”}.

In the second test case, 
The suggestion for “n” is {“ninjas”}.
The suggestion for “ni” is {“ninjas”}.
The suggestion for “nin” is {“ninjas”}.
The suggestion for “ninj” is {“ninjas”}.
The suggestion for “ninja” is {“ninjas”}.
The suggestion for “ninjas” is {“ninjas”}.
Sample Input 2 :
3
2
coding ninjas
cell
2
ab abc
a
2
ab abc
b
Sample Output 2 :
coding
ab abc
No suggestions found
Explanation To Sample Input 2 :
In the first test case, 
The suggestion for “c” is {“coding”}.
For the rest of the letters, there are no suggestions.

In the second test case,
The suggestion for “a” is {“ab”, “abc”}.

In the third test case, no suggestions are found.




*/







class trieNode{
    public:
    
    trieNode* children[26];
    
    string letter;
    
    bool isEnd;
    
    trieNode(){
        
        for(int i=0;i<26;i++){
            
            children[i]=NULL;
        }
        
        letter = "";
        
        isEnd = false;
    }
     ~trieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != NULL)
            {
                delete children[i];
            }
        }
    }
};
void insert(string contact,trieNode* root){
    
    trieNode* curr = root;
    
    int contactLength = contact.length();
    
    int i;
    
    for( i=0;i<contactLength;i++){
        
        int index = contact[i]-'a';
        
        if(curr->children[index]==NULL)
        {
            curr->children[index] = new trieNode();
            
            curr->children[index]->letter = contact[i];
        }
        
        curr=curr->children[index];
    }
    if(i==contactLength){
        
        curr->isEnd =true;
    }
}
void DFS(trieNode* root,string s, vector<string>&smallAns){
    
    if(root==NULL){
      
        return;
    }
    trieNode*curr = root;
    
    if(curr->isEnd==true){
        
        smallAns.push_back(s);
    }
    for(int i=0;i<26;i++){
        
        if(curr->children[i]==NULL){
          
            continue;
        }
        
        DFS(curr->children[i],s+curr->children[i]->letter,smallAns);
    }  
    return;
}

void query(string smallQuery,vector<vector<string>> &result, trieNode* root){
    
    trieNode* curr = root;
    
    vector<string> smallAns;
    
    int length = smallQuery.length();
    
    int i;
    
    for(i=0;i<length;i++){
        
        int index = smallQuery[i]-'a';
        
        if(curr->children[index]==NULL){
          
            return;
        }
      
        curr = curr->children[index];
    }
  
    if(i==length){
        
        DFS(curr,smallQuery,smallAns);
        
        result.push_back(smallAns);
    }
}


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    trieNode* root = new trieNode();
    
    //insert contactList in trie
    
   for(int i=0;i<contactList.size();i++){
     
       insert(contactList[i],root);
   }
   
   vector<vector<string>> result;
    
    // query after adding each letter of queryStr
    
    int length = queryStr.length();
    
    string word = "";
    
    for(int i=0;i<length;i++){
        
        word+=queryStr[i];
        
        query(word,result,root);
    }
  
    delete root;
  
    return result;
}

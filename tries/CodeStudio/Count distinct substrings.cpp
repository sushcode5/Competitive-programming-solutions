/*
              Name - Rindhe Sushil Samadhan
              IIT Guwahati

*/



#include<bits/stdc++.h>
using namespace std;
class trieNode{
    public:
    trieNode* children[26];
    trieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
     ~trieNode(){
        for (int i = 0; i < 26; i++){
            if (children[i] != NULL){
                delete children[i];
            }
        }
    }
};
void insert(string s, trieNode* root, int pos,int length){
    trieNode* curr = root;
    for(int i=pos;i<length;i++){
        int index = s[i]-'a';
        if(!curr->children[index]){
            curr->children[index] = new trieNode();
        }
        curr=curr->children[index];
    }
}
int countNodes(trieNode* root){
    trieNode* curr = root;
    if(root==NULL){
        return 0;
    }
    int count = 1;
    for(int i=0;i<26;i++){
        count += countNodes(curr->children[i]);
    }
    return count;
}
int countDistinctSubstrings(string s){
  
    trieNode* root = new trieNode();
  
    int length = s.length();
  
    //insert all substrings
    for(int i=0;i<length;i++){
        insert(s,root,i,length);
    }
   // count all distinct substrings
    int count = countNodes(root);
   
   // free the memory
    delete root;
  
    return count;
    
}

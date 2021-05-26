/*
       Name - Rindhe Sushil Samadhan
       IIT Guwahati
       
*/


/*

You are given a string 'S' of length 'N' consisting of lowercase English alphabet letters. You are also given a positive integer 'K'.
Now, a substring of this string is good if it contains at most 'K' distinct characters. A string 'X' is a substring of string 'Y' if it can be obtained by deletion of several continuous elements(possibly zero) from the beginning and the end from the string 'Y'.
Your task is to return the maximum size of any good substring of the string 'S'.



*/


 // Brutforce Approach
// Time Complexity - O(N^3)

#include<bits/stdc++.h>
using namespace std;
int findCount(string s, int k){
    int n = s.length();
    unordered_set<char> set;
    int count = 0;
    for(int i=0;i<n;i++){
        if(set.find(s[i]) == set.end()){
            count++;
            set.insert(s[i]);
        }
    }
    if(count <= k){
        return n;
    }
    else{
        return -1;
    }
}
int getLengthofLongestSubstring(string s, int k) {
    int n = s.length();
    int maxLength = 0;
    
    for(int i=0;i<n;i++){
        string substring = "";
        for(int j=i;j<n;j++){
            substring.push_back(s[j]);
            //find length of longest substring starting with i which has at most k distinct elements.
            int count = findCount(substring, k);
            maxLength = max(maxLength, count);
        }
    }
    
    return maxLength;
}



// we need to optimised above solution.

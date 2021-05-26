
/*
             Name - Rindhe Sushil Samadhan
             IIT Guwahati
             
             
*/



/*

You have been given two strings, let's say "str1" and "str2" of equal lengths. You are supposed to return the minimum number of manipulations required to make the two strings anagrams.
An anagram is a word or phrase formed by rearranging the letters of a different word or phrase. We can generalise this in string processing by saying that an anagram of a string is another string with the same quantity of each character in it, in any order.


*/



#include<bits/stdc++.h>
using namespace std;
int getMinimumAnagramDifference(string &str1, string &str2)
{
    vector<int> freq1(26,0);
    vector<int> freq2(26,0);
    for(int i=0;i<str1.length();i++){
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++; 
    }
    
    int ans = 0;
    
    for(int i=0;i<26;i++){
        ans += abs(freq1[i] - freq2[i]);
    }
    return ans/2;
}

/* 
           Name - Rindhe Sushil Samadhan
           IIT Guwahati
           
 */


/*

You are given a string STR of length N. Your task is to remove all the vowels present in that string and print the modified string.
English alphabets ‘a’, ‘e’, ‘i’, ‘o’, ‘u’ are termed as vowels. All other alphabets are called consonants.
Note: You have to only remove vowels from the string. There will be no change in the relative position of all other alphabets.


*/


#include<bits/stdc++.h>
using namespace std;
string removeVowels(string inputString) {
    unordered_set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
     vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
    
    
    string output = "";
    int n = inputString.length();
    for(int i=0;i<n;i++){
        if(vowels.find(inputString[i]) == vowels.end()){
            output.push_back(inputString[i]);
        }
    }
    return output;
}

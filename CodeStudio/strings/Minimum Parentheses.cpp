/*
         Name - Rindhe Sushil Samadhan
         IIT Guwahati
         
*/



/*

Given a string "pattern", which contains only two types of characters ‘(’, ‘)’.
Your task is to find the minimum number of parentheses either ‘(’, ‘)’ we must add the parentheses in string ‘pattern’ and the resulted string is valid.
Condition for valid string-
Every opening parenthesis ‘(’ must have a correct closing parenthesis ‘)’.
Example - ‘(()(()))’, ‘()()()’, ‘((()))’ are valid string, and ‘(((’, ‘(()’, ‘)(())’ are invalid string.



*/




#include<bits/stdc++.h>
using namespace std;
int minimumParentheses(string pattern) {
    
    int n = pattern.length();
    int openCnt = 0;
    int closeCnt = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(pattern[i] == '('){
            openCnt++;
        }
        else{
            closeCnt++;
        }
        if(closeCnt > openCnt){
                ans += closeCnt - openCnt;
                closeCnt = 0;
                openCnt = 0;
            }
    }
    
    ans += openCnt - closeCnt;
    return ans;
    
}


/*               Name - Rindhe Sushil Samadhan
                 IIT Guwahati
*/

/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").



*/



#include <iostream>
#include<string.h>
using namespace std;
int countPalindromeSubstrings(char s[]) {
    int n = strlen(s);
    int count=0;
    for(int i=0;i<n;i++){
        int l =i;
        int r =i;
        //for odd length pallindrome
        while(l>=0 && r<n && s[l]==s[r]){
           count++;
            
            l--;
            r++;
        }
        //for even length pallindrome
        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            count++;
            l--;
            r++;
        }    
        
    }
    return count;
}
int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}

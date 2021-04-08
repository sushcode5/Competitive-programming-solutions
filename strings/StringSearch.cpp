/*
                   
                     Name - Rindhe Sushil Samadhan
                     IIT Guwahati
                     
*/



/*
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1


*/



#include <iostream>
#include<string.h>
using namespace std;
int* getLPS(char T[],int lenT){
    int i=1;
    int j=0;
    int *lps = new int[lenT];
    lps[0]=0;
    while(i<lenT){
        if(T[i]==T[j]){
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    return lps;
}
int findString(char S[], char T[]){
   int lenS = strlen(S);
   int lenT = strlen(T);
    int* lps = getLPS(T,lenT);
    int i=0;
    int j=0;
    while(i<lenS && j<lenT){
        if(S[i]==T[j]){
            i++;
            j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j= lps[j-1];
            }
        }
    }
    if(j==lenT){
        return i-j;
    }
    else{
        return -1;
    }
    
}
int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

/*
         Name - Rindhe Sushil Samadhan
         IIT Guwahati
         
 */

/*

You are given a string 'STR'. You have to convert the first alphabet of each word in a string to UPPER CASE.

*/


#include<string>
string convertString(string str) 
{
    int val = str[0] - 96;
    if(val > 0){
        char smallLetter = str[0];
        str[0] = smallLetter - 32;
    }
	for(int i=0; i< str.length() - 1; i++){
        
        if(str[i] == ' ' && str[i+1] != ' '){
            int val = str[i+1] - 96;
            if(val > 0){
                char smallLetter = str[i+1];
                str[i+1] = smallLetter - 32;
            }
        }
    }  
   return str;
}

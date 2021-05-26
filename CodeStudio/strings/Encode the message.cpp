/* 
        Name - Rindhe Sushil Samadhan
        IIT Guwahati
       
*/



/*


You have been given a text message. You have to return the Run-length Encoding of the given message.
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as the character and a single count. For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".


*/
#include <iostream>
#include<string>
using namespace std;
string encode(string &message){
    
    int n = message.length();
    string output = "";
    
    for(int i=0;i<n;i++){
        char currLetter = message[i];
        int letterFreq  = 1;
        
        while(i+1 < n && message[i+1] == currLetter){
            i++;
            letterFreq++;
        }
        
        output.push_back(currLetter);
        output.append(to_string(letterFreq));
    }
    return output;
    
}
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        string word;
        cin>>word;
        cout<<encode(string)<<endl;
    }

    return 0;
}





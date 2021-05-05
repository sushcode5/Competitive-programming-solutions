/*      
            Name - Rindhe Sushil Samadhan
            IIT Guwahati
 
*/

/*Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions*/



#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26
class trieNode{
    public:
    char letter;
    
    bool isWord; //is word ended
    trieNode** children;
    
    trieNode(){
        children = new trieNode*[ALPHABET_SIZE];
        for(int i=0;i<ALPHABET_SIZE;i++){
            children[i]=NULL;
        }
        isWord = false;
        letter = '\0';
    }
};
void insert(string s,trieNode* root){
    trieNode* curr = root;
    int i;
    for(i=0;i<s.length();i++){
        int index = s[i] -'a';
        
        if(curr->children[index]){
            curr = curr->children[index];
        }
        else{
            curr->children[index] = new trieNode();
            curr ->children[index]->letter = s[i];
            curr = curr ->children[index];
        }
    }
    if(i == s.length()){
        curr->isWord = true;
    }
    return;
}
void DFS(trieNode* root, string s){
    if(root->isWord){
        cout<<s<<endl;
    }
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]){
            DFS(root->children[i], s+root->children[i]->letter);
        }
    }
}
int query(string s, trieNode*root){
    trieNode* curr = root;
    for(int i=0;i<s.length();i++){
        int index = s[i] - 'a';
        if(!curr->children[index]){
            return 0;
        }
        curr= curr->children[index];
    }
    DFS(curr, s);
    return 1;
}
int main(){
    int n;
    cin>>n;
    trieNode* root = new trieNode();
    
    string s;
    for(int i=0;i<n;i++){
       
       cin>>s;
       insert(s,root);
    }
    int q;
    int answer=0;
    cin>>q;
    string search;
    for(int i=0;i<q;i++){
        
        cin>>search;
         answer = query(search, root);
         if(answer==0){
             cout<<"No suggestions"<<endl;
             insert(search,root);
         }
    }
    return 0;
}

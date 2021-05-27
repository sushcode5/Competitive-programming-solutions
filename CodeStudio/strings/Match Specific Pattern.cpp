
/*
       Name - Rindhe Sushil Samadhan
       IIT Guwahati
       
 */












/*
	Time complexity: O(N * length(Pattern))
	Space Complexity: O(length(pattern))
	
	Where N is the number of words in the list.
*/

#include <unordered_map>

bool matchSpecificPatternHelper(string &word, string &pattern)
{	
	// Check if length of word is not equal to length of pattern
    if (word.length() != pattern.length())
    {
        return false;
    }
	
    // Maintain two HashMap
    unordered_map<char, char> mapPat, mapWord;
	
    // Iterate through the string pattern
    for (int i = 0; i < pattern.length(); i++)
    {
        char chW = word[i], chP = pattern[i];

        if (mapPat.find(chP) == mapPat.end() && mapWord.find(chW) == mapWord.end())
        {
            mapPat[chP] = chW;
            mapWord[chW] = chP;
        }
        else if (mapPat.find(chP) != mapPat.end() && mapPat[chP] != chW)
        {
            return false;
        }
        else if (mapWord.find(chW) != mapWord.end() && mapWord[chW] != chP)
        {
            return false;
        }
    }

    return true;
} 

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{	
    // Create an array to store all valid strings
    vector<string> ans;

    // Iterate over all the words.
    for (int i = 0; i < n; i++)
    {
        string word = words[i];

        bool isValid = matchSpecificPatternHelper(word, pattern);
		
        // Check if isValid is equal to true
        if (isValid)
        {
            ans.push_back(word);
        }
    }
	
    // Return the array ans
    return ans;
}

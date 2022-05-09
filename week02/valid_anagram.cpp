//Problem 11: Valid Anagram.

//Solution:

// Time complexity: O(N), where N is the length of the string.
// Space complexity: O(1)

bool isAnagram(string s, string t){
    if(s.length() != t.length()) return false;
    int charCount[26] = {0};
    int stringLength = s.length();
    for(int i = 0; i < stringLength; i++){
        charCount[s[i] - 'a']++;
    }
    for(int i = 0; i < stringLength; i++){
        charCount[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(charCount[i] != 0) return false;
    }
    return true;
}

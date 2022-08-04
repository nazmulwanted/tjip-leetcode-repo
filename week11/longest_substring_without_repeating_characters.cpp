// Time complexity: O(N) , N = Length of the given string.
// Space complexity: O(1)

int lengthOfLongestSubstring(string s){
    int longestSubstringLength = 0;
    vector<int> characterCount(256, 0);
    int left = 0;
    int right = 0;
    int duplicateCount = 0;
    int strLen = s.length();
    while(right < strLen){
        characterCount[s[right]]++;
        if(characterCount[s[right]] > 1){
            duplicateCount++;
        }
        right++;
        while(duplicateCount > 0){
            characterCount[s[left]]--;
            if(characterCount[s[left]] == 1){
                duplicateCount--;
            }
            left++;
        }
        longestSubstringLength = max(longestSubstringLength, right - left);
    }
    return longestSubstringLength;
}

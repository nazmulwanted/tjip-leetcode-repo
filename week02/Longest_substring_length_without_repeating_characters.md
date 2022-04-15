#### Problem 1: Longest substring without repeating characters (Easy)
___

###### Solution

```c++
// Time complexity: O(n)
// where, n = number of characters in the string and
// Space complexity: O(1)

int lengthOfLongestSubstring(string s){
    vector<int> characterCount(256, 0);
    int longestSubStrLen = 0;
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
        longestSubStrLen = max(longestSubStrLen, right - left);
    }
    return longestSubStrLen;
}
```

// Time complexity: O(N), N = string length
// Space complexity: O(N), N = string length

int lengthOfLongestSubstringKDistinct(string s, int k){
    unordered_map<char, int> chrMap;
    int max_substring_length = 0;
    int left = 0;
    int string_length = s.length();
    int num_of_distincts = 0;

    for(int right = 0; right < string_length; right++){
        if(chrMap.count(s[right]) == 0) num_of_distincts++;

        chrMap[s[right]]++;

        while(num_of_distincts > k){
            if(chrMap[s[left]] > 1) chrMap[s[left]]--;
            else{
                chrMap.erase(s[left]);
                num_of_distincts--;
            }
            left++;
        }
        max_substring_length = max(max_substring_length, right - left + 1);
    }

    return max_substring_length;
}

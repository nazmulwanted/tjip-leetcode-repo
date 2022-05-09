// Time complexity: O(N), where N = string length
// Space complexity: O(N)

bool isIsomorphic(string s, string t, int iteration_count = 0){
    unordered_map<char, char> mp;
    for(int i = 0; i < s.size(); i++){
        if(mp.count(s[i]) && mp[s[i]] != t[i]) return false;
        mp[s[i]] = t[i];
    }
    if(iteration_count == 0) return isIsomorphic(t, s, 1);
    return true;
}

// Time complexity: O(N), N = string length
// Space complexity: O(N), N = string length

int countOfWays(int pos, string &s, vector<int> &cache){
    if(pos >= s.size() || s[pos] == '0') return pos == s.size();
    if(cache[pos] != -1) return cache[pos];
    cache[pos] = countOfWays(pos+1, s, cache);
    if(stoi(s.substr(pos, 2)) <= 26) cache[pos] += countOfWays(pos+2, s, cache);
    return cache[pos];
}

int numDecodings(string s){
    vector<int> cache(s.size() + 1, -1);
    return countOfWays(0, s, cache);
}

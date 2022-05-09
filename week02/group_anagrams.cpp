//Problem 6: Group anagrams. (Difficulty: Medium)

//Solution:

// Time complexity: O(N), where N is number of strings.
// Space complexity: O(N)

unsigned long long getHash(string& str){
    unsigned long long hashValue = 1;
    for(auto ch: str){
        hashValue = hashValue * (257 + (ch - 'a'));
    }
    return hashValue;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<unsigned long long, vector<string>> lists;
    for(auto &str: strs){
        lists[getHash(str)].push_back(str);
    }
    vector<vector<string>> anagramList;
    for(auto &item: lists){
        anagramList.push_back(item.second);
    }
    return anagramList;
}

// Time complexity: O(n^2), n = string length;
// Space complexity: O(n^2), n = string length;

string find_longest_palindrome(string &s, vector<vector<bool>> &palindrome_table){
    string result = "";
    result += s[0];
    int str_length = s.size();
    for(int i = 0; i < str_length; i++) palindrome_table[i][i] = true;
    for(int i = str_length - 1; i >= 0; i--){
        for(int j = i+1; j < str_length; j++){
            if(s[i] == s[j] && ((j - i == 1) || (palindrome_table[i+1][j-1]))){
                palindrome[i][j] = true;
                if(j-i+1 > result.size()) result = s.substr(i, j-i+1);
            }
        }
    }
    return result;
}

string longestPalindrome(string s){
    if(s.size() == 0) return "";
    vector<vector<bool>> palindrome_table(s.size(), vector<bool> (s.size(), false));
    return find_longest_palindrome(s, palindrome_table);
}

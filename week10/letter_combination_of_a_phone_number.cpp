// Time complexity: O(N * 4 ^ N), N = Length of digits. 
// Space complexity: O(N * 4 ^ N), N = Length of digits. 

void genCombination(string currStr, int pos, string &digits, vector<string> &digitLetterList, vector<string> &combinationList){
    if(pos == digits.size()){
        combinationList.push_back(currStr);
        return;
    }
    int digit = digits[pos] - '0';
    for(auto letter: digitLetterList){
        genCombination(currStr + letter, pos + 1, digits, digitLetterList, combinationList);
    }
}

vector<string> letterCombinations(string digits){
    if(digits.size() == 0) return {};
    vector<string> combinationList;
    vector<string> digitLetterList = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    string currStr;
    genCombination(currStr, 0, digits, digitLetterList, combinationList);
    return combinationList;
}

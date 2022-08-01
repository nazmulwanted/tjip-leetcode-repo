// Time complexity: O(2 ^ (2 * n)) 
// Space complexity: O(2 ^ (2 * n))

void generateBrackets(string currStr, int open, int close, vector<string> &bracket_list){
    if(open == close && open == 0){
        bracket_list.push_back(currStr);
        return;
    }
    if(open > 0) generateBrackets(currStr + "(", open - 1, close, bracket_list);
    if(open < close) generateBrackets(currStr + ")", open, close - 1, bracket_list);
}

vector<string> generateParenthesis(int n){
    vector<string> bracket_list;
    generateBrackets("", n, n, bracket_list);
    return bracket_list;
}

// Time complexity: O(N), N = Number of characters in the string.
// Space complexity: O(total count of possible numbers in the string)

int calculate(string s){
    long long currNum = 0;
    long result = 0;
    stack<int> stk;
    char sign = '+';
    int s_length = s.size();
    for(int i = 0; i < s_length; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            currNum = 10 * currNum + s[i] - '0';
        }
        if(!(s[i] >= '0' && s[i] <= '9') && (s[i] != ' ') || i == s_length - 1){
            if(sign == '+') stk.push(currNum);
            else if(sign == '-') stk.push(-1 * currNum);
            else{
                if(sign == '*') currNum = stk.top() * currNum;
                else currNum = stk.top() / currNum;
                stk.pop();
                stk.push(currNum);
            }
            currNum = 0;
            sign = s[i];
        }
    }
    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }
    return result;
}

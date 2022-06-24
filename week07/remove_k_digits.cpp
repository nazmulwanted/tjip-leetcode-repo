// Time complexity: O(N) , N = Length of the string.
// Space complexity: O(N), N = Length of the string.

string removeKdigits(string num, int k){
    stack<char> stk;

    for(auto &n : num){
        while(!stk.empty() && k > 0 && stk.top() > c){
            stk.pop();
            k--;
        }
        stk.push(c);
    }

    while(k > 0 && !stk.empty()){
        stk.pop();
        k--;
    }

    string result;
    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }
    while(!result.empty() && result.back() == '0'){
        result.pop_back();
    }
    if(result.empty()) return "0";
    reverse(result.begin(), result.end());
    return result;
}

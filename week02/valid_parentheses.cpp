//Problem 4: Valid Parentheses

//Solution:

//Time complexity: O(N), where N is string length
//Space complexity: O(N)

bool isValid(string s){
    int strLength = s.length();
    int stackTop = 0;
    string myStack;

    for(int i = 0; i < strLength; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            myStack += s[i];
            stackTop++;
        }
        else if(s[i] == ')'){
            if(stackTop == 0) return false; // if stack is already empty return false.
            top--;
            if(myStack[stackTop] != '(') return false;
            myStack.pop_back();
        }
        else if(s[i] == '}'){
            if(stackTop == 0) return false; // if stack is already empty return false.
            top--;
            if(myStack[stackTop] != '{') return false;
            myStack.pop_back();
        }
        else if(s[i] == ']'){
            if(stackTop == 0) return false; // if stack is already empty return false.
            top--;
            if(myStack[stackTop] != '[') return false;
            myStack.pop_back();
        }
    }

    if(stackTop == 0) return true;
    else return false;
}

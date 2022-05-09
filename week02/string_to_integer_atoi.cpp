//Problem 2: String to integer (atoi) (Medium)

//Solution:

// Time complexity: O(N), where N is given string length.
// Space complexity: O(1)

int myAtoi(string s) {
        bool isThereNumber = false;
        bool isNumberStarted = false;
        bool isNegative = false;
        int strLength = s.length();
        int numberLength = 0;
        int i;
        for(i = 0; i < strLength; i++){
            if(isNumberStarted && (s[i] == '+' || s[i] == '-' || s[i] == ' ') && numberLength == 0){
                return 0;
            }
            else if(isNumberStarted && (s[i] == '+' || s[i] == '-' || s[i] == ' ')){
                isNumberStarted = false;
                break;
            }
            else if(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9')){
                isNumberStarted = true;
                isThereNumber = true;
                if(s[i] == '-') isNegative = true;
                if(s[i] >= '0' && s[i] <= '9') numberLength++;
            }
            else {
                 if(isNumberStarted) break;
                 else if(!isNumberStarted && 
                     ((s[i] >= 'a' && s[i] <= 'z') || 
                     (s[0] >= 'A' && s[0] <= 'Z') || 
                     s[0] == '.')) return 0;  
            }
        }
        
        if(isThereNumber) {
            string numStr = s.substr(i - numberLength, numberLength);
            int result = 0;
            for(int j = 0; j < numberLength; j++){
                if(result > INT_MAX / 10 || 
                    (result == INT_MAX / 10 && numStr[j] - '0' > 7)) {
                    return isNegative? INT_MIN : INT_MAX;
                }
                result = (result * 10) + (numStr[j] - '0');
            }
            return isNegative? -1 * result : result;
        }
        else return 0;
}

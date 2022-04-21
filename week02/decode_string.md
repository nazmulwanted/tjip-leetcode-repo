##### Problem 12: Decode String (Difficulty: Medium)
___

#### Solution

```c++
// Time Complexity: O(N)
// Space Complexity: O(N)

string decodingString(string& s, int& i){
    string res;
    int strLen = s.length();
    while(i < strLen && s[i] != ']'){
        // checking if s[i] is a digit
        if(!isdigit(s[i]){
            res += s[i];
            i++;
        }
        else{
            int num = 0;
            while(i < strLen && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i++; // skipping '['
            string tmp = decodingString(s, i);
            i++; // skipping ']'

            while(num > 0){
                res += tmp;
                num--;
            }
        }
    }
    return res;
}

string decodeString(string s){
    int i = 0;
    return decodingString(s, i);
}
```

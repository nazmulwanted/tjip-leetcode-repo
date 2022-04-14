#### Problem 4: Longest Common Prefix (Easy)
___

###### Solution

```c++
// Time complexity: O(n * m)
// where, n = number of strings in the vector and
// m = number of common characters ( length of common prefix )
// Space complexity: O(1)

string longestCommonPrefix(vector<string>& strs){
    if(strs.size()) == 1){
        return strs[0];
    }
    else{
        int numberOfStrings = strs.size();
        string currentLCP = strs[0];
        for(int i = 1; i < numberOfStrings; i++){
            int j;
            for(int j = 0; j < strs[i].length(); j++){
                if(strs[i][j] != currentLCP[j]) break;
            }
            currentLCP = currentLCP.substr(0, j);
        }
        return currentLCP;
    }
}
```

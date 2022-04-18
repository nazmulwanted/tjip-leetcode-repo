#### Problem 5: Implement strStr()
___

##### Solution

```c++
//Time Complexity: O(N) where N is the length of haystack string.
//Space Complexity: O(1)

int strStr(string haystack, string needle){
    if(needle == "") return 0;
    else {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        for(int i = 0; i <= (haystackLength - needleLength); i++){
            if(haystack[i] == needle[0] &&
                haystack.substr(i, needleLength) == needle){
                return i;
            }
        }
        return -1;
    }
}
```

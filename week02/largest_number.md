##### Problem 8: Largest Number (Difficulty: Medium)
___

#### Solution

```c++
// Time complexity: O(N) + O(NlogN) where N is number of elements
// in the nums vector.
// Space complexity: O(N)

static bool compareFunction(string a, string b){
    return a + b > b + a;
}

string largestNumber(vector<int>& nums){
    int numsSize = nums.size();
    if(numsSize == 1){
        return to_string(nums[0]);
    }
    else{
        vector<string> bucket;
        for(int i = 0; i < numsSize; i++){
            bucket.push_back(to_string(nums[i]));
        }
        sort(bucket.begin(), bucket.end(), compareFunction);
        string result;
        for(int i = 0; i < numsSize; i++){
            result += bucket[i];
        }
        return result[0] == '0'? "0" : result;
    }
}
```

// Time complexity: O(N), N = Number of elements in an array.
// Space complexity: O(N), N = Number of elements in an array.

int subarryDivByK(vector<int> &nums, int k){
    unordered_map<int, int> seenPrefixSumModK;
    seenPrefixSumModK[0] = 1;
    int subArrayCount = 0;
    int prefixSum = 0;

    for(auto &num: nums){
        prefixSum += num;
        while(prefixSum < 0) prefixSum += k;
        int rem = prefixSum - k;
        if(rem < 0) rem += k;
        if(seenPrefixSumModK.count(prefixSum % k)){
            subArrayCount += seenPrefixSumModK[prefixSum % k];
        }
        seenPrefixSumModK[prefixSum]++;
    }

    return subArrayCount;
}

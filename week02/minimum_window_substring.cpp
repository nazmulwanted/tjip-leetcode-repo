//Problem 7: Minimum Window Substring (Difficulty: Hard)

//Solution:

// Time complexity: O(N) where N is string s length.
// Space complexity: O(1)

string minWindow(string s, string t){
    vector<int> freqT(130, 0);
    for(auto ch: t) freqT[ch]++;

    int remCharOfT = t.length();
    int left = 0, right = 0, minLength = INT_MAX / 2, startIndx = - 1;
    int sLength = s.length();

    while(right < sLength){
        if(freqT[s[right]] > 0) remCharOfT--;
        freqT[s[right]]--;
        right++

        while(remCharOfT == 0){
            if(minLength > right - left){
                minLength = right - left;
                startIndx = left;
            }
            if(freqT[s[left]] == 0) remCharOfT++;
            freqT[s[left]]++;
            left++;
        }
    }
    return startIndx == -1? "" : s.substr(startIndx, minLength);
}

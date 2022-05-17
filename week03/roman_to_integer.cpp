// Time complexity: O(N), N = Given string length.
// Space complexity: O(N)

int romanToInt(string s){
    unordered_map<char, int> value_table = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        int sum = 0;
        int string_length = s.length();
        for(int i = 0; i < string_length; i++){
            if(i+1 <= string_length && value_table[s[i+1]] > value_table[s[i]]){
                sum += (value_table[s[i+1]] - value_table[s[i]]);
                i++;
            }
            else sum += value_table[s[i]];
        }
        return sum;
    };
}

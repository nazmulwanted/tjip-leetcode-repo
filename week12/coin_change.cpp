// Time complexity: O(Given amount)
// Space complexity: O(Given amount)

int find_min_coins(vector<int> &cache, vector<int> &coins, int amount){
    if(amount == 0) return 0;
    if(cache[amount] != -1) return cache[amount];
    int min_coins = INT_MAX / 2;
    for(auto &coin: coins){
        if(amount >= coin){
            min_coins = min(min_coins, 1 + find_min_coins(cache, coins, amount - coin));
        }
    }
    return cache[amount] = min_coins;
}

int coinChange(vector<int> &coins, int amount){
    vector<int> cache(amount + 1, -1);
    int min_coins = find_min_coins(cache, coins, amount);
    return min_coins > amount ? -1 : min_coins;
}

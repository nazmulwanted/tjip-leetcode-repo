// Time complexity: O(N * log(log(N)) , N = Given integer number.
// Space complexity: O(N)

int sieve(int n){
    vector<bool> comp(n + 5, false);
    comp[1] = true;
    for(int i = 2; i * i <= n; i++){
        if(comp[i] == false){
            for(int j = i * i; j <= n; j += i){
                comp[j] = true;
            }
        }
    }
    int count = 1;
    for(int i = 3; i < n; i += 2){
        if(comp[i] == false) count++;
    }
    return count;
}

int countPrimes(int n){
    if(n == 0 || n == 1 || n == 2) return 0;
    return sieve(n);
}

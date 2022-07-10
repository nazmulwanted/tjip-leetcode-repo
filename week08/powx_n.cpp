// Time complexity: O(log N), N is the power of the base.
// Space complexity: O(1)

double modularExpo(double x, long long n){
    if(n == 0) return 1.0;
    if(n % 2 == 0){
        double res = modularExpo(x, n / 2);
        return res * res;
    }
    return x * modularExpo(x, n - 1);
}

double myPow(double x, int n){
    if(n == 0) return 1.0;
    bool inverse_flag = n < 0;
    long long N = n < 0? (-1) * 1LL * n : n;
    double result = modularExpo(x, N);
    result = inverse_flag ? 1.0 / result : result;
    return result;
}

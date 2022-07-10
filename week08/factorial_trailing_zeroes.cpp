//Time complexity: O(Count of 5 in the n's factorial's divisors).
//Space complexity: O(1)
int trailingZeroes(int n){
    int count_5 = 0;
    int div = 5;
    while(n >= div){
        count_5 += n / div;
        div *= 5;
    }
    return count_5;
}

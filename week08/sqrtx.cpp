// Time complexity: O(log N) , N = given Number;
// Space complexity: O(1)

int mySqrt(int x){
    long long left = 0, right = x;
    while(left < right){
        long long mid = left + (right - left + 1) / 2;
        if(mid * mid > x) right = mid - 1;
        else left = mid;
    }
    return right;
}

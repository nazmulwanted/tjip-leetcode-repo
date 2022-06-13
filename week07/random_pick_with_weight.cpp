// Time complexity: O(N) + O(log N) , N = Array size.
// Space complexity: O(N), N = Array Size;


mt19937 rd(0);

vector<int> weight_sum;

int getRandomValueInRange(int left, int right){
    return left + (rd() % (right - left + 1));
}

Solution(vector<int> &w){
    weight_sum = w;
    int weight_sum_size = weight_sum.size();
    for(int i = 1; i < weight_sum_size; i++){
        weight_sum[i] = w[i] + weight_sum[i - 1];
    }
}

int pickIndex(){
    int totalSum = weight_sum.back();
    int random_value = getRandomValueInRange(1, totalSum);
    return lower_bound(weight_sum.begin(), weight_sum.end(), random_value) - weight_sum.begin();
}

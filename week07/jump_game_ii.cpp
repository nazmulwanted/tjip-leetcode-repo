// Time complexity: O(N), N = Array length
// Space complexity: O(1)

int jump(vector<int> &nums){
    int position_index = nums.size() - 1;
    int number_of_jumps = 0;
    while(position_index != 0){
        for(int i = 0; i < position_index; i++){
            if(nums[i] >= position_index - i){
                position_index = i;
                number_of_jumps++;
                break;
            }
        }
    }
    return number_of_jumps;
}

// Time complexity: O(log N), N = Array length or size of the matrix.
// Space complexity: O(1)

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int left = 0;
    int right = matrix[0].size() * matrix.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        int row = mid / matrix[0].size();
        int column = mid % matrix[0].size();
        if(matrix[row][column] == target) return true;
        if(matrix[row][column] > target){
            right = mid - 1;
        }
        else if(matrix[row][column] < target){
            left = mid + 1;
        }
    }
    return false;
}

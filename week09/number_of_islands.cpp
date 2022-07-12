// Time complexity: O(M * N), M = Number of rows, N = Number of columns of the grid.
// Space complexity: O(1)

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(vector<vector<char>> &grid, int row, int col){
    int r = grid.size();
    int c = grid[0].size();
    if(row == r || col == c || row < 0 || col < 0) return;
    if(grid[row][col] == '0' || grid[row][col] == '2') return;
    grid[row][col] = '2';
    for(int i = 0; i < 4; i++){
        dfs(grid, row + dr[i], col + dc[i]);
    }
}

int numIslands(vector<vector<char>> &grid){
    int row = grid.size();
    int col = grid[0].size();
    int count = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

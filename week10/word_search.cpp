// Time complexity: O(M * N * 3 ^ L), M = Width of the board, N = Height of the board, L = Word length.
// Space complexity: O(L), L = Word length.

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

bool traverseBoard(vector<vector<char>> &board, string &word, int &m, int &n, int pos, int x, int y){
    if(x < 0 || x >= m || y < 0 || y >= n || word[pos] != board[x][y]) return false;
    if(pos == word.size() - 1) return true;
    bool status = false;
    char ch = board[x][y];
    board[x][y] = '#';
    for(int i = 0; i < 4; i++){
        status |= traverseBoard(board, word, m, n, pos+1, x + dx[i], y + dy[i]);
    }
    board[x][y] = ch;
    return status;
}

bool exist(vector<vector<char>> &board, string word){
    if(word.size() == 0) return true;
    if(board.size() == 0 || board[0].size() == 0) return false;
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(traverseBoard(board, word, m, n, 0, i, j)) return true;
        }
    }
    return false;
}

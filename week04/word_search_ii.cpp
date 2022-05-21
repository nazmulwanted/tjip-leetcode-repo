class trieNode{
public:
    string word;
    trieNode* next[26];
    trieNode(){
        word = "";
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

vector<int> dir{-1, 0, 1, 0, -1};

trieNode* generateTrie(vector<string> &words){
    trieNode* root = new trieNode();
    for(auto &wd: words){
        trieNode* currNode = root;
        for(auto &c: wd){
            int order = c - 'a';
            if(currNode->next[order] == NULL){
                currNode->next[order] = new trieNode();
            }
            currNode = currNode->next[order];
        }
        currNode->word = wd;
    }
    return root;
}

void dfs(int x, int y, vector<vector<char>> &board, trieNode* currNode, vector<string> &wordsOnBoard){
    char ch = board[x][y];
    if(ch == '#' || (currNode && currNode->next[ch-'a'] == NULL)) return;
    currNode = currNode->next[ch-'a'];

    if(currNode && currNode->word.size() > 0){
        wordsOnBoard.push_back(currNode->word);
        currNode->word.clear();
    }

    board[x][y] = '#';

    for(int i = 0; i < 4; i++){
        int X = x + dir[i];
        int Y = y + dir[i+1];
        if(X < 0 || Y < 0 || X >= board.size() || Y >= board[0].size() || board[X][Y] == '#') continue;
        dfs(X, Y, board, currNode, wordsOnBoard);
    }

    board[x][y] = ch;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words){
    trieNode* root = generateTrie(words);
    vector<string> wordsOnBoard;
    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dfs(i, j, board, root, wordsOnBoard);
        }
    }
    return wordsOnBoard;
}

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

trieNode* generateTrie(vector<string>& products){
    trieNode* root =  new trieNode();
    for(auto &wd: products){
        trieNode* curr = root;
        for(auto c: wd){
            int order = c - 'a';
            if(curr->next[order] == NULL){
                curr->next[order] = new trieNode();
            }
            curr = cur->next[order];
        }
        curr->word = wd;
    }
    return root;
}

void dfs(trieNode* u, vector<string>& words){
    if(u == NULL || words.size() == 3) return;
    if(u->word.size() > 0 && words.size() < 3){
        words.push_back(u->word);
    }
    for(int i = 0; i < 26; i++){
        dfs(u->next[i], words);
    }
}

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWword){
    trieNode* root = generateTrie(products);
    vector<vector<string>> suggestions;
    for(auto c: searchWord){
        root = root && root->next[c-'a'] ? root->next[c-'a'] : NULL;
        vector<string> words;
        dfs(root, words);
        suggestions.push_back(words);
    }
    return suggestions;
}

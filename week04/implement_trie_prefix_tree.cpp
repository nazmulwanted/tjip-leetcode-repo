// Time complexity: Around O(N * M) where N is Number of strings and M is average length of the strings.
// Space complexity: Around O(N * M) or less.

class TrieNode{
public:
    bool isWord;
    TrieNode* next[26];
    TrieNode(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

class Trie{
public:
    TrieNode root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode currNode = root;
        for(auto c: word){
            int order = c - 'a';
            if(currNode->next[order] == NULL){
                currNode->next[order] = new TrieNode();
            }
            currNode = currNode->next[order];
        }
        currNode->isWord = true;
    }

    bool search(string word, bool isPrefixSearch = false){
        TrieNode currNode = root;
        for(auto c: word){
            int order = c - 'a';
            if(currNode->next[order] == NULL){
                return false;
            }
            currNode = currNode->next[order];
        }
        return currNode && (currNode->isWord || isPrefixSearch);
    }

    bool startsWith(string prefix){
        return search(prefix, true);
    }
};

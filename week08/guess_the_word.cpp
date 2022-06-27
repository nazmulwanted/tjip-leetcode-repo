// Time complexity: O(N), N = Number of strings.
// Space complexity: O(N)

int calculateScore(string &ref, string &candidate){
    int res = 0;
    int ref_length = ref.size();
    for(int i = 0; i < ref_length; i++){
        res += ref[i] == candidate[i];
    }
    return res;
}

void findSecretWord(vector<string> &wordlist, Master &master){
    while(wordlist.size() > 1){
        int rnd_index = rand() % wordlist.size();
        string query_string = wordlist[rnd_index];
        int score = master.guess(query_string);
        vector<string> new_word_list;
        for(auto &word: wordlist){
            if(calculateScore(word, query_string) == score){
                new_word_list.push_back();
            }
        }
        wordlist = new_word_list;
    }
    master.quess(wordlist[0]);
}

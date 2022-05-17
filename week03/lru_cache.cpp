//Problem 2: LRU cache

list<int> lru;
unordered_map<int, list<int>::iterator> mp;
unordered_map<int, int> kv;
int max_cap;

LRUCache(int capacity){
    max_cap = capacity;
}

int get(int key){ // Time complexity: O(1)
    if(kv.count(key) == 0){
        return -1;
    }
    updateLRU(key);
    return kv[key];
}

int put(int key, int value){ // Time complexity: O(1)
    if(kv.size() == max_cap && kv.count(key) == 0){
        evict();
    }
    updateLRU(key);
    kv[key] = value;
}

void updateLRU(int key){
    if(kv.count(key)){
        lru.erase(mp[key]);
    }
    lru.push_front(key);
    mp[key] = lru.begin();
}

void evict(){
    mp.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
}

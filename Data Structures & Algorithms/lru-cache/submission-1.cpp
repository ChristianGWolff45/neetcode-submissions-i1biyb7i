class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> location;
    int maxSize;
    int currSize;
    LRUCache(int capacity) {
        currSize = 0;
        maxSize = capacity;
    }
    
    int get(int key) {
        if (!location.contains(key)) return -1;
        int value = location[key]->second;
        cache.erase(location[key]);
        cache.push_back({key,value});
        location[key] = prev(cache.end());
        return (*location[key]).second;
    }
    
    void put(int key, int value) {
        if(location.contains(key)){
            cache.erase(location[key]);
            cache.push_back({key,value});
            location[key] = prev(cache.end());
        }
        else {
            if(currSize == maxSize){
                int oldKey = cache.begin()->first;
                cache.erase(location[oldKey]);
                location.erase(oldKey);
                currSize--;

            }
            cache.push_back({key, value});
            location[key] = prev(cache.end());
            currSize++;
        }
    }
};

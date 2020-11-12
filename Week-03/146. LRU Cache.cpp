class LRUCache {
    
    list<int> cache;
    unordered_map<int, pair<list<int>::iterator, int> > present;
    int size;
    
public:
    LRUCache(int capacity) {
        //cache.resize(capacity);
        size=capacity;
    }
    
    int get(int key) {
        if(present.find(key) == present.end()){
            //cout << "front:" << cache.front() << "back:" << cache.back() << endl;
            //cout << "get:" << key <<"->" << -1 << endl;
            return -1;
        }
        cache.erase(present[key].first);
        cache.push_front(key);
        present[key].first=cache.begin();
        
        //cout << "front:" << cache.front() << "back:" << cache.back() << endl;
        //cout << "get:" << key <<"->" << present[key].second << endl;
        
        return present[key].second;
    }
    
    void put(int key, int value) {
        //cout << "front:" << cache.front() << "back:" << cache.back() << endl;
        //cout << "put:" << key <<"->" << value << endl;
        if(present.find(key) == present.end()) {
            if(cache.size()<size) {
                cache.push_front(key);
                present[key]={cache.begin(), value};
            } else if(cache.size()==size) {
                int last_element=cache.back();
                cache.pop_back();
                present.erase(last_element);
                
                cache.push_front(key);
                present[key]={cache.begin(), value};    
            }
        } else {
            cache.erase(present[key].first);
            cache.push_front(key);
            present[key]={cache.begin(), value};
        }
        
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

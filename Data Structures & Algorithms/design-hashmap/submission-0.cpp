class MyHashMap {
public:
    static constexpr int EMPTY = -1;
    static constexpr int DELETED = -2;
    static constexpr int n= 10000;
    pair<int, int> arr[n];
    MyHashMap() { 
        for (int i = 0; i < n; ++i)
            arr[i] = {EMPTY, 0};
    }
    
    void put(int key, int value) {
        int hkey = hash<int>{}(key);
        for (int i = 0; i < n; ++i) {
            int slot = (hkey + i)%n;
            if (arr[slot].first == EMPTY || arr[slot].first == key) { 
                arr[slot] = {key, value}; 
                return;
            } else if (arr[slot].first == DELETED || arr[slot].first != key) {
                continue;
            }
        }
        // shoudl be unreachable
    }
    
    int get(int key) {
        int hkey = hash<int>{}(key);
        for (int i = 0; i < n; ++i) {
            int slot = (hkey + i)%n;
            if (arr[slot].first == EMPTY) {return -1;}
            else if (arr[slot].first == key) { return arr[slot].second; }
            else if (arr[slot].first == DELETED || arr[slot].first != key) {continue;}
        }
        return -1;
    }
    
    void remove(int key) {
        int hkey = hash<int>{}(key);
        for (int i = 0; i < n; ++i) {
            int slot = (hkey + i)%n;
            if (arr[slot].first == key) {
                arr[slot].first = DELETED;
                return;
            }
            else if (arr[slot].first == EMPTY) {break;}
            else if (arr[slot].first == DELETED || arr[slot].first != key) {continue;}
        }
    }
};

/**
 * Your Myhash<int>{}Map object will be instantiated and called as such:
 * Myhash<int>{}Map* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
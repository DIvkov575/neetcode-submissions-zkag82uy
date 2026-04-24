class MyHashSet {
    static constexpr int size = 197;
    vector<int> arr_[size];
public:
    MyHashSet() { }
    
    void add(int key) {
        vector<int>& slot = arr_[key % size];
        for (int i = 0; i < slot.size(); ++i) {
            if (slot[i] == key) {
                return;
            }
        }
        slot.push_back(key);
        
    }
    
    void remove(int key) {
        vector<int>& slot = arr_[key % size];
        for (int i = 0; i < slot.size(); ++i) {
            if (slot[i] == key) {
                slot.erase(slot.begin() + i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        for (int elt: arr_[key % size]) {
            if (elt == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class RandomizedSet {
public:
    std::vector<int> elts;
    std::unordered_map<int, int> mp;

    std::mt19937 rng;

    RandomizedSet()
        : rng(std::random_device{}()) {
    }
    
    bool insert(int val) {
        if (mp.find(val)  != mp.end()) return false;

        mp[val] = elts.size();
        elts.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;

        size_t elt_idx = mp[val];
        swap(elts[elt_idx], elts[elts.size() - 1]);
        elts.pop_back();
        mp[elts[elt_idx]] = elt_idx;
        
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> dist(0, elts.size()-1);
        return elts[dist(rng)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
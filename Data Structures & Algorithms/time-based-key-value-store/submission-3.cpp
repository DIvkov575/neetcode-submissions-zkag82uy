#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {
        // Default constructor
    }

    void set(const string& key, const string& value, int timestamp) {
        map[key].push_back({timestamp, value});
    }

    string get(const string& key, int timestamp) {
        if (map.find(key) == map.end()) return ""; 

        const vector<pair<int, string>>& data = map[key];
        int l = 0, h = data.size() - 1;
        int res = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (data[m].first <= timestamp) {
                res = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        if (res == -1) return ""; 
        return data[res].second;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> v;
        for (int i = 0; i < n; ++i) 
            v.push_back({position[i], speed[i]});

        sort(v.begin(), v.end()); 

        int fleets = 0;
        float top_time = 0;

        for (int i = n - 1; i >= 0; --i) {
            float t = (target - v[i].first) / (float)v[i].second;

            if (t > top_time) {
                fleets++;
                top_time = t;
            }
        }

        return fleets;
    }
};

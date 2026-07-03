class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<int> output(m, -1);

        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < m; ++i) { sortedQueries.push_back({queries[i], i}); } // query, oindx
        sort(sortedQueries.begin(), sortedQueries.end());

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return ((a.second - a.first) > (b.second - b.first)); };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> hp(cmp);

        int si = 0;
        for (int i = 0; i < m; ++i) {
            int query = sortedQueries[i].first;
            int originalIndex = sortedQueries[i].second;

            while (si < n && intervals[si][0] <= query) { 
                hp.push({intervals[si][0], intervals[si][1]});
                ++si;
            }
            while (!hp.empty() && hp.top().second < query) { hp.pop(); }

            if (hp.empty()) {continue;}
            output[sortedQueries[i].second] =
                (hp.top().second - hp.top().first + 1);
        }

        return output;
    }
};
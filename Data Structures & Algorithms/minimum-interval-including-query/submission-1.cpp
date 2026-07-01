class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<int> output(m, numeric_limits<int>::max());

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < m; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        int si = 0;
        for (int i = 0; i < m; ++i) {
            int query = sortedQueries[i].first;
            int originalIndex = sortedQueries[i].second;

            while (si < n && intervals[si][1] < query) {
                ++si;
            }

            int sj = si;
            while (sj < n && intervals[sj][0] <= query) {
                if (intervals[sj][1] >= query) {
                    output[originalIndex] = min(
                        output[originalIndex],
                        intervals[sj][1] - intervals[sj][0] + 1
                    );
                }
                ++sj;
            }
        }

        for (int i = 0; i < output.size(); ++i) {
            if (output[i] == numeric_limits<int>::max()) {
                output[i] = -1;
            }
        }

        return output;
    }
};
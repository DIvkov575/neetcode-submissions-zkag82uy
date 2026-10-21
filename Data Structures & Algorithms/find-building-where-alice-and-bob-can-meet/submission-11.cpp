class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int k = queries.size();
        if (n == 1) { return vector<int>(k, 0); }

        stack<pair<int,int>> s;

        vector<int> nh(n);

        for (int i =n-1; i >= 0; --i) {
            while (!s.empty() && heights[i] >= s.top().first) { s.pop(); }

            if (s.empty()) { 
                nh[i] = -1; }
            else { 
                nh[i] = s.top().second;
            }
            s.push({heights[i], i});
        }

        // return nh;

        vector<int> out(k, -1);
        for (int i = 0; i < k; ++i) {
            int a = queries[i][0];
            int b = queries[i][1];

            if (a > b) { swap(a,b); }

            if (heights[a] < heights[b] || a==b) {
                out[i] = b;
            } else {
                if (nh[a] == -1 || nh[b] == -1) {
                    out[i] = -1;
                } else {
                    for (int j = max(nh[a], nh[b]); j < n; ++j) {
                        if (heights[j] > heights[a]) {
                            out[i] = j;
                            break;
                        }
                    }

                    // int l = max(nh[a], nh[b]); int r=n-1;
                    // while (l < r) {
                    //     int m = l + (r-l)/2;

                    //     if (nh[m] == -1 || heights[nh[m]] > heights[a]) {
                    //         r = m;
                    //     } else {
                    //         l = m + 1;
                    //     }
                    // }
                    // if (heights[l] > heights[a]) {
                    //     out[i] = l;
                    // } else {
                    //     out[i] = -1;
                    // }

                }

            }
        }

        return out;

    }
};

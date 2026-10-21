class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), k = queries.size();
        vector<int> out(k, -1);
        vector<vector<pair<int,int>>> atB(n); // atB[b] = {threshold height, query idx}

        for (int i = 0; i < k; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) out[i] = b;
            else atB[b].push_back({heights[a], i});
        }

        // st holds indices: bottom = rightmost/tallest, top = nearest/shortest
        vector<int> st;
        for (int j = n - 1; j >= 0; --j) {
            // answer queries with b == j using buildings strictly right of j
            for (auto [t, qi] : atB[j]) {
                // find topmost stack entry with height > t
                int lo = 0, hi = (int)st.size() - 1, ans = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (heights[st[mid]] > t) { ans = st[mid]; lo = mid + 1; }
                    else hi = mid - 1;
                }
                out[qi] = ans;
            }
            while (!st.empty() && heights[st.back()] <= heights[j]) st.pop_back();
            st.push_back(j);
        }
        return out;
    }
};
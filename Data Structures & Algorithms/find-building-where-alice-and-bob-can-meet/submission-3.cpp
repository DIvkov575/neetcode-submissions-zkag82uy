class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int k = queries.size();
        if (n == 1) { return vector<int>(k, 0); }

        // stack<pair<int,int>> s;

        // vector<int> nh(n);

        // for (int i =n-1; i >= 0; --i) {
        //     while (!s.empty() && heights[i] >= s.top().first) { s.pop(); }

        //     if (s.empty()) { 
        //         nh[i] = -1; }
        //     else { 
        //         nh[i] = s.top().second;
        //     }
        //     s.push({heights[i], i});
        // }

        // return nh;

        // vector<int> out(k);
        // for (int i = 0; i < k; ++i) {
        //     int a = queries[i][0];
        //     int b = queries[i][1];

        //     if (a > b) { swap(a,b); }

        //     if (heights[a] < heights[b] || a==b) {
        //         out[i] = b;
        //     } else {
        //         if (nh[a] == -1 || nh[b] == -1) {
        //             out[i] = -1;
        //         } else {
        //             out[i] = max(nh[a], nh[b]);

        //         }

        //     }
        // }

        // return out;

        // int n = heights.size(), k = queries.size();
        vector<int> out(k, -1);
        vector<vector<pair<int,int>>> pending(n); // pending[b] = {needed height, query idx}

        for (int i = 0; i < k; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) out[i] = b;
            else pending[b].push_back({max(heights[a], heights[b]), i});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int j = 0; j < n; ++j) {
            while (!pq.empty() && pq.top().first < heights[j]) {
                out[pq.top().second] = j;
                pq.pop();
            }
            for (auto& p : pending[j]) pq.push(p);
        }
        return out;;

    }
};

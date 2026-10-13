class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> G(n+1);
        vector<int> d(n+1);
        for (int i = 0; i < times.size(); ++i) {
            int ui = times[i][0];
            int vi = times[i][1];
            int ti = times[i][2];
            G[ui].push_back({vi, ti});
        }
        for (int i = 0; i < n; ++i) {
            d[i+1] = INT_MAX;
        }
        d[k] = 0;
        int visited = 1;

        priority_queue<int> pq;
        pq.push(k);

        while (!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            for (auto [ni, dt]: G[cur]) {
                if (d[cur] + dt < d[ni]) {
                    if (d[ni] == INT_MAX) {visited++;}

                    d[ni] = d[cur] + dt;
                    pq.push(ni);
                }
            }
            // if (visited == n) {
            //     break;
            // }
        }

        if (visited != n) {
            return -1;
        } else {
            int maxv = 0;;
            for (int i = 1; i < n+1; ++i) {
                maxv = max(maxv,d[i]);
            }
            return maxv;
        }


    }  
};

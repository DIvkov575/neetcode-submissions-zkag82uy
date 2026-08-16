class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int kg) {
        vector<vector<int>> distances(n, vector<int>(kg+2, numeric_limits<int>::max()));
        vector<vector<pair<int, int>>> neighbors(n);

        for (vector<int>& flight: flights) {
            neighbors[flight[0]].push_back(make_pair(flight[2], flight[1]));
        }

        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, src, 0});
        distances[src][0] = 0;

        while (!pq.empty()) {
            auto [ndistance, src_node, k] = pq.top();
            pq.pop();

            int distance = -ndistance;

            if (src_node == dst) return distance;
            if (k == kg + 1) continue;

            for (auto [weight, node]: neighbors[src_node]) {
                if (distance + weight < distances[node][k+1]) {
                    distances[node][k+1] = distance + weight;
                    pq.push({-(distance + weight), node, k+1});
                }
            }
        }

        return -1;
    }
};
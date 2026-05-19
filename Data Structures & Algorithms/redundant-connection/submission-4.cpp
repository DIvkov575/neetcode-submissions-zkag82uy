class Solution {
public:
    class DSU {
        vector<int> comp, sz;

    public:
        DSU(int n) : comp(n), sz(n, 1) {
            iota(comp.begin(), comp.end(), 0);
        }

        int find(int x) {
            if (comp[x] != x)
                comp[x] = find(comp[x]);
            return comp[x];
        }

        bool unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if (px == py) return false;

            if (sz[px] < sz[py]) swap(px, py);

            comp[py] = px;
            sz[px] += sz[py];

            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);

        for (auto &e : edges) {
            if (!dsu.unite(e[0], e[1]))
                return e;
        }

        return {};
    }
};
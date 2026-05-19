class Solution {
public:
    class DSU {
        private:
            vector<int> comp;
            vector<int> sizes;
        public:
            DSU (int n) {
                comp = vector<int>(n);
                iota(comp.begin(), comp.end(),0);
                sizes = vector<int>(n, 1);
            }

            bool eq(int x, int y) {
                if (find(x) == find(y)) {
                    return true;
                } else {
                    return false;
                }
            }

            void uni(int x, int y) {
                int fx = find(x);
                int fy = find(y);

                if (sizes[fx] < sizes[fy]) {
                    comp[fx] = comp[fy];
                    sizes[fy] += sizes[fx];
                } else {
                    comp[fy] = comp[fx];
                    sizes[fx] += sizes[fy];
                }
            }

            int find(int x) {
                if (comp[x] != x) {
                    comp[x] = find(comp[x]);
                }

                return comp[x];
            }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // Kruskals/Prims - negative
        // DFS
        // BFS / Khans

        DSU dsu(edges.size()+1);

        
        vector<int> edge;

        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            
            if (dsu.eq(a,b)) { edge = edges[i]; }
            dsu.uni(a,b);
        }

        return edge;
    }
};

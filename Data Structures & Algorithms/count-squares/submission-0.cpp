class CountSquares {
public:
    unordered_multiset<int> x[1000];
    unordered_multiset<int> y[1000];

    CountSquares() {}

    void add(vector<int> point) {
        x[point[0]].insert(point[1]);
        y[point[1]].insert(point[0]);
    }

    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];

        auto &xms = x[px];

        int total = 0;

        for (int y2 : xms) {
            if (y2 == py) continue;

            int side = y2 - py;

            // try square on both directions
            for (int dx : {side, -side}) {
                int nx = px + dx;

                if (nx < 0 || nx >= 1000) continue;

                auto &col = x[nx];

                // count matches of (nx, py) and (nx, y2)
                int c1 = col.count(py);
                int c2 = col.count(y2);

                total += c1 * c2;
            }
        }

        return total;
    }
};
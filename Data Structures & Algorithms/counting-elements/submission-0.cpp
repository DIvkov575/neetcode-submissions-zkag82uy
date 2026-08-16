class Solution {
public:
    int countElements(vector<int>& arr) {
        const int N = 1001;
        int counts[N] = {};
        for (int elem: arr) {
            ++counts[elem];
        }
        int total{};
        for (int i = 1; i < N; ++i) {
            if (counts[i] > 0) {
                total += counts[i-1];
            }
        }
        return total;
    }
};

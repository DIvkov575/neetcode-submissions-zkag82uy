#include <algorithm>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<vector<int> > out;
        out.reserve(k);

        auto comp = [](auto a, auto b){
            return (a[0]*a[0] + a[1]*a[1]) > (b[0]*b[0] + b[1]*b[1]);
        };
        std::make_heap(points.begin(), points.end(), comp);


        for (int i = 0; i < k; ++i) {
            out.push_back(points[0]);
            std::pop_heap(points.begin(), points.end(),comp);
            points.pop_back();
        }

        return out;

        
    }
};

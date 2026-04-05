class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;

        auto getval = [&matrix](int val){ return matrix[val / matrix[0].size()][val % matrix[0].size()]; };

        while (low < high) {
            int mid = (low + high) / 2;

            if (target > getval(mid)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (getval(low) == target) {
            return true;
        } else {
            return false;
         
        }
        
    }
};

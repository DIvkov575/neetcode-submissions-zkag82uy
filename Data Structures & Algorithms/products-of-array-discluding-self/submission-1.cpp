class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
                int num_zeros = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { num_zeros += 1; }
        }
 
        if (num_zeros > 1) {
            return vector<int>(nums.size(), 0);

        } else if (num_zeros == 1) {
            vector<int> output(nums.size(), 0);
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    output[i] = 1;
                    for (int j = 0; j < nums.size(); ++j) { // multiplication loop
                        if (i != j) {
                            output[i] *= nums[j];
                        }
                    }
                    return output;
                }
            }
            return output;
        } else {
            int acc = 1;
            for (int i = 0; i < nums.size(); ++i) {
                acc *= nums[i];
            }
            vector<int> output(nums.size(), acc);
            for (int i = 0; i < nums.size(); ++i) {
                output[i] /= nums[i];
            }

            return output;
        }
    }
};

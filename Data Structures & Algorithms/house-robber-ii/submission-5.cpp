class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        else if (nums.size() == 2) {return max(nums[0], nums[1]);}
        else if (nums.size() == 3) {return max(nums[0], max(nums[1], nums[2]));}
        
        int tmp;
        int a = nums[1];
        int b = nums[0];

        tmp = a;
        a = b + nums[2];
        b = max(tmp, b);

        for (int i = 3;i < nums.size() - 1; ++i) {
            tmp = a;
            a = max(a,b + nums[i]);
            b = max(tmp, b);
        }
        int first_value = max(a,b);

        // 

        a = nums[2];
        b = nums[1];
        for (int i = 3;i < nums.size(); ++i) {
            tmp = a;
            a = max(a,b + nums[i]);
            b = max(tmp, b);
        }

        // a = max(a,b + nums[0]);
        // b = max(tmp, b);
        int second_value = max(a,b);

        return max(first_value, second_value);




        
    }
};

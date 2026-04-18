class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        int tmp;
        int a = nums[1];
        int b = nums[0];

        for (int i = 2;i < nums.size(); ++i) {
            tmp = a;
            a = max(a,b + nums[i]);
            b = max(tmp, b);
        }

        return max(a,b);


        

        
    }
};

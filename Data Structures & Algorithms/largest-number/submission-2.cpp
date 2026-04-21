class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        strs.reserve(nums.size());

        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        struct Less {
            bool operator()(const string& a, const string& b) const {
                return a + b > b + a;
            }
        };

        sort(strs.begin(), strs.end(), Less{});

        string buffer;
        for (auto& s : strs) buffer += s;

        if (!buffer.empty() && buffer[0] == '0') return "0";
        return buffer;
    }
};
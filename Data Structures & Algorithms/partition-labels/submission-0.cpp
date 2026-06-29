class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> output;
        int lastoc[26];

        for (int i = 0; i < s.size(); ++i) {
            lastoc[s[i] - 'a'] = i;
        }


        int l = 0;
        while (l < s.size()) {
            int n = lastoc[s[l] - 'a'];
            for (int r = l; r < n; ++r) {
                n = max(n, lastoc[s[r] - 'a']);
            }
            output.push_back(n-l+1);
            l = n + 1;
        }

        return output;



        
    }
};

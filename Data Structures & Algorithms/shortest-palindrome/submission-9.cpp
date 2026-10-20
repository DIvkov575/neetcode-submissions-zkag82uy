class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();

        if (n < 2) {
            return s;
        }

        for (int len = n; len > 0; len--) {
            int l = 0, r = len - 1;
            while (l < r && s[l] == s[r]) {
                l++;
                r--;
            }

            if (r - l > 0) {
                continue;
            }
            string tail = s.substr(len);
            reverse(tail.begin(), tail.end());
            return tail + s;
        }
        string tail = s.substr(1);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
};
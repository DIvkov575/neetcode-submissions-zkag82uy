class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            for (int i = 0; i < s.length() - 1; ++i) {
                s[i] = char(( int(s[i]-'0') + int(s[i+1] - '0')) % 10 + '0');
            }
            s.erase(s.length()-1, 1);
        }

        return (s[0] == s[1]);

        
    }
};

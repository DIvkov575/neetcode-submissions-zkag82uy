class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t sptr = 0;
        size_t tptr = 0;

        while (sptr < s.size() && tptr < t.size()) {
            while (tptr < t.size() && s[sptr] != t[tptr]) ++tptr;
            ++tptr;
            ++sptr;
        }

        return (sptr == s.size());
        
    }
};
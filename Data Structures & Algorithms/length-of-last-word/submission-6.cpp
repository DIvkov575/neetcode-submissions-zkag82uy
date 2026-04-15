class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 1 && s[0] == ' ') { return 0; }
        else if (s.size() == 1 && s[0] != ' ') { return 1; }

        size_t sptr = s.size() - 1;
        while (sptr >0 && s[sptr] == ' ') {--sptr;}

        size_t ub = sptr;
        while (sptr > 0 && s[sptr] != ' ') {--sptr;}

        return ub - sptr;

        
    }
};
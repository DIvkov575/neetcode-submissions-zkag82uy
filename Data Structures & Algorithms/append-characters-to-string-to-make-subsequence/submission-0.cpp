class Solution {
public:
    int appendCharacters(string s, string t) {
        // int counts[26]; // ts wrong ik

        size_t tptr = 0;
        size_t sptr = 0;

        while (tptr < t.size() && sptr < s.size()) {
            if (t[tptr] == s[sptr]) {++tptr; ++sptr;}

            while (sptr < s.size() && t[tptr] != s[sptr]) {
                ++sptr;
            }


        }


        return t.size() - tptr;

        
        
    }
};
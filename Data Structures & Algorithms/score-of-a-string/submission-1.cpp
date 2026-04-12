#include <cstdlib>

class Solution {
public:
    int getScore(char ch) {
        return ch - 'a';
    }
    int scoreOfString(string s) {
        int acc = 0;
        for (int i = 1; i < s.size(); ++i) {
            acc += std::abs(getScore(s[i]) - getScore(s[i-1]));
        }
        return acc;


        
    }
};
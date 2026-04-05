class Solution {
public:
    bool isPalindrome(string raw) {
        std::string s;

        for (unsigned char c : raw)
            if (std::isalnum(c))
                s+= c;
        // s.erase(remove_if(s.begin(), s.end(), [](){

        // }))
        for (int i = 0; i < (s.size() / 2); ++i) {
            if (tolower(s[i]) != tolower(s[s.size() - i - 1])) {
                return false;
            }
        }
        return true;
    }
};

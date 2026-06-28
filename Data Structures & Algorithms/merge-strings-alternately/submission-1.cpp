class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        vector<char> buf;


        for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
            buf.push_back(word1[i]);
            buf.push_back(word2[i]);
        }

        if (word1.size() < word2.size()) {
            for (int i = word1.size(); i < word2.size(); ++i) {
                buf.push_back(word2[i]);
            }
        } else {
            for (int i = word2.size(); i < word1.size(); ++i) {
                buf.push_back(word1[i]);
            }
        }

        return string(buf.begin(), buf.end());


        
    }
};
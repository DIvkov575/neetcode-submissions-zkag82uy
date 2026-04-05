class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > grouping;
        for (string str: strs) {
            string str_sorted = str;
            sort(str_sorted.begin(), str_sorted.end());

            if (grouping.find(str_sorted) == grouping.end()) {
                grouping[str_sorted] = {str};
            } else {
                grouping[str_sorted].push_back(str);
            }
        }

        vector< vector<string> > grouping_v;
        for (pair<string, vector<string> > elem: grouping) {
            grouping_v.push_back(elem.second);
        }

        return grouping_v;
        
    }
};

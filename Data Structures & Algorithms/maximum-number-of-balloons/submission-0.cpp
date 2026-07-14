class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int counts[26];

        for (char c: text) { ++counts[c - 'a']; }
        int minocs = std::numeric_limits<int>::max();
        
        minocs = min(minocs, counts['l'-'a']/2);
        minocs = min(minocs, counts['o'-'a']/2);
        minocs = min(minocs, counts['b'-'a']);
        minocs = min(minocs, counts['a'-'a']);
        minocs = min(minocs, counts['n'-'a']);

        return minocs;
    }
};

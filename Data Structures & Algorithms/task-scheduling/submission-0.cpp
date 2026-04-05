#include <queue>
#include <algorithm>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char t : tasks)
        freq[t - 'A']++;

    int f_max = *max_element(freq.begin(), freq.end());
    
    int count_max = 0;
    for (int f : freq)
        if (f == f_max)
            count_max++;

    int total = tasks.size();

    return max(total, (f_max - 1) * (n + 1) + count_max);
        
    }
};

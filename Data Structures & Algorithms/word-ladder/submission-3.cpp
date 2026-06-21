class Solution {

    static bool checkWord(string worda, string wordb) {
        bool diference_flag = false;
        for (int i = 0; i < worda.size(); ++i) { // this really should be refactored - revisit
            if (worda[i] != wordb[i]) {
                if (diference_flag) {
                    return false;
                } else {
                    diference_flag = true;
                }
            }
        }

        return diference_flag; // should be true
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        wordList.push_back(beginWord);
        wordList.push_back(endWord);

        int n = wordList.size();
        int bindx = n - 2;
        int endx = n - 1;

        vector<vector<bool>> E(n, vector<bool>(n, false));

        // build graph - this is slow
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (checkWord(wordList[i], wordList[j])) {
                    E[i][j] = true;
                    E[j][i] = true;
                }
            }
        }

        // bfs lol

        int MAX = std::numeric_limits<int>::max();
        vector<int> distances(n, MAX);
        distances[bindx] = 0;

        deque<int> q({bindx});

        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();

            for (int i = 0; i < n; ++i) {
                if (E[cur][i] && distances[cur] + 1 < distances[i]) {
                    distances[i] = distances[cur] + 1;
                    q.push_back(i);
                }
            }
        }

        if (distances[endx] != MAX) {
            return distances[endx]+1;
        } else {
            return 0;
        }
    }
};
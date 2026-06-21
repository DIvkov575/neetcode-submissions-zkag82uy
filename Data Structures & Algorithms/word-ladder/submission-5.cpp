#include <bits/stdc++.h>
using namespace std;

class Solution {

    static bool checkWord(const string& a, const string& b) {
        bool diff = false;

        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != b[i]) {
                if (diff) return false;
                diff = true;
            }
        }

        return diff;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return 0;

        int endx = it - wordList.begin();

        wordList.push_back(beginWord);
        int bindx = wordList.size() - 1;

        int n = wordList.size();
        const int INF = numeric_limits<int>::max();

        vector<int> dist(n, INF);
        deque<int> q;

        dist[bindx] = 1;
        q.push_back(bindx);

        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();

            if (cur == endx) return dist[cur];

            for (int i = 0; i < n; ++i) {
                if (dist[i] == INF && checkWord(wordList[cur], wordList[i])) {
                    dist[i] = dist[cur] + 1;
                    q.push_back(i);
                }
            }
        }

        return 0;
    }
};
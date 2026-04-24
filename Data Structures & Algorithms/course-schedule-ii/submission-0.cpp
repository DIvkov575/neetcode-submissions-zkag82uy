#include<queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        order.reserve(numCourses);

        unordered_set<int> inG;
        unordered_map<int, vector<int>> G;
        vector<int> inCount(numCourses, 0);

        for (vector<int> prereq : prerequisites) {
            inG.insert(prereq[0]);
            inG.insert(prereq[1]);
            G[prereq[1]].push_back(prereq[0]);
            ++inCount[prereq[0]];
        }

        deque<int> dq;
        for (int i = 0; i < numCourses; ++i) {
            if (inG.contains(i) && inCount[i] == 0) {
                dq.push_back(i);
            } else if (!inG.contains(i)) {
                order.push_back(i);
            }
        }

        while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();

            order.push_back(cur);

            for (int neighbor: G[cur]) {
                if (--inCount[neighbor] == 0) {
                    dq.push_back(neighbor);
                }
            }
        }

        for (int i =0; i < numCourses; ++i) {
            if (inCount[i] != 0) {
                return {};
            }
        }
        return order;
    }
};

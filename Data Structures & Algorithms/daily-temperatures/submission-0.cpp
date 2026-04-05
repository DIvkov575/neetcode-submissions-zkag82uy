class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());

        stack<int> idxs;

        int i = temperatures.size() - 1;
        idxs.push(i);
        --i;
        for (; i >= 0; --i) {
            if (temperatures[i] < temperatures[idxs.top()]) {
                answer[i] = idxs.top() - i;
                idxs.push(i);
            } else {
                while (!idxs.empty() &&(temperatures[i] >= temperatures[idxs.top()])) {
                    idxs.pop();
                }

                !idxs.empty() ? answer[i] = idxs.top() - i :  answer[i] = 0;
                idxs.push(i);
            }
        }

        return answer;
        
    }
};
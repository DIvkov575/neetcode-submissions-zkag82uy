class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;

        for (string op: operations) {
            if (op == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();

                s.push(a); // not sure to re-ad
                s.push(a + b);
            } else if (op == "D") {
                int a = s.top();
                s.push(2*a);
            } else if (op == "C") {
                s.pop();
            } else {
                s.push(stoi(op));
            }
        }

        int acc = 0;
        while (!s.empty()) {
            acc += s.top();
            s.pop();
        }

        return acc;
        
    }
};
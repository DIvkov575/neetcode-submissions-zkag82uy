class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& st : tokens) {
            if (st == "+") {
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs + rhs);
            } else if (st == "-") {
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs - rhs);
            } else if (st == "*") {
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs * rhs);
            } else if (st == "/") {
                int rhs = s.top(); s.pop();
                int lhs = s.top(); s.pop();
                s.push(lhs / rhs);
            } else {
                s.push(stoi(st)); 
            }
        }
        
        return s.top();
    }
};

class Solution {
public:
    bool isValid(string str) {
               stack<char> s;

        for (char ch: str) {
            switch (ch) {
                case '(':
                    s.push('(');
                    break;
                case ')':
                    if ((s.size() == 0) || (s.top() != '(')) {
                        return false;
                    }
                    s.pop();
                    break;
                case '[':
                    s.push('[');
                    break;
                case ']':
                    if ((s.size() == 0) || (s.top() != '[')) {
                        return false;
                    }
                    s.pop();
                    break;
                case '{':
                    s.push('{');
                    break;
                case '}':
                    if ((s.size() == 0) || (s.top() != '{')) {
                        return false;
                    }
                    s.pop();
                    break;
            };
        }

        if (s.empty()) {
            return true;
        } else {
            return false;
        }
         
    }
};

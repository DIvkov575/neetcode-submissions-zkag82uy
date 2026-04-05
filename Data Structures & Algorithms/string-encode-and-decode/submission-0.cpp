class Solution {
public:

    string encode(vector<string>& strs) {
        string buf = "";
        for (string str: strs) {
            for (char ch: str) {
                switch(ch) {
                    case ',':
                        buf += "\\,";
                        break;
                    case '\\':
                        buf += "\\";
                        break;
                    default:
                        buf += ch;
                        break;
                }
            }
            buf += ",";
        }

        return buf;
    }

    vector<string> decode(string s) {
        vector<string> output;
        string buf = "";
        for (auto it = s.begin(); it != s.end(); ++it) {

            char fch = *it;
            char sch;
            switch (fch) {
                case '\\':
                    sch = *(++it);

                    if (sch == '\\') {
                        buf += '\\';
                    } else if (sch == ',') {
                        buf += ',';
                    }  else {
                        buf += fch;
                        buf += sch;
                    }
                    break;
                case ',':
                    output.push_back(buf);
                    buf = "";
                    continue;
                default:
                    buf += fch;
                    break;
            }
        }
        output.push_back(buf);
        output.pop_back();

        return output;
    }
};

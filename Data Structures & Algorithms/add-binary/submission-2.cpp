class Solution {
public:
    string addBinary(string a, string b) {
        vector<bool> av(a.size());
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '1') { av[a.size() - i -1] = true;
            } else { av[a.size() - i -1] = false; }
        }
        vector<bool> bv(b.size());
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == '1') { bv[b.size() - i -1] = true;
            } else { bv[b.size() - i -1] = false; }
        }
        vector<char> out;
        out.reserve(a.size() + b.size() + 1);;
        bool carry = false;
        int ptr1 = 0;
        int ptr2 = 0;
        bool state;

        while (true) {
            int ptr3 = max(ptr1, ptr2);

            if (ptr1 < a.size() && ptr2 < b.size()) {
                state = av[ptr1] ^ bv[ptr2] ^ carry;
                carry = ((av[ptr1] && bv[ptr2]) ||
                    (bv[ptr2] && carry) ||
                    (carry && av[ptr1]));
                ++ptr1;
                ++ptr2;
            } else if (ptr1 < a.size() && ptr2 == b.size()) {
                state = av[ptr1] ^ carry;
                carry = av[ptr1] && carry;
                ++ptr1;
            } else if (ptr1 == a.size() && ptr2 < b.size()) {
                state = bv[ptr2] ^ carry;
                carry = bv[ptr2] && carry;
                ++ptr2;
            } else {
                if (carry) {
                    out.push_back('1');
                }
                break;
            }

            if (state) {
                out.push_back('1');
            } else {
                out.push_back('0');
            }
        }

        return string(out.rbegin(), out.rend());
    }
};
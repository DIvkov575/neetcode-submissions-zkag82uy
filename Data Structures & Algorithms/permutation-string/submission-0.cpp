#include<array>
#include<print>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        array<int, 26> signature{};
        array<int, 26> mp2{}; // buffer
        int l = 0;
        int r = 0;

        // s1 full, s2 anythign
        if (s1.size() == 0) { return true; }
        // if ((s2.size() == 0) && (s1.size() == 0)) {return true;}
        if  ((s2.size() == 0) && (s1.size() !=0)) /* second condition always true */ {return false;}
        if (s2.size() < s1.size()) {return false;}

        for (char ch: s1) { ++signature[ch - 'a']; }

        int idx = s2[l] - 'a';
        ++mp2[idx];

        // for (int num : signature) {cout << num << " ";} cout << "\n" <<endl;
        // for (int num : mp2) {cout << num << " ";} cout << "\n" <<endl;

        // iter through s2
        while (r < s2.size() - 1) {
            // cout << r << endl;

            idx = s2[r] - 'a';
            if (signature[idx] > mp2[idx]) { 
                // cout << "a \n";
                idx = s2[++r] - 'a';
                ++mp2[idx];
            } else if (signature[idx] < mp2[idx]) {
                // cout << "b \n";
                while ((signature[idx] < mp2[idx]) && (l <= r)) {
                    int idx_tmp = s2[l] - 'a';
                    // cout << "idx_tmp " << idx_tmp << endl;
                    --mp2[idx_tmp];
                    ++l;
                }
                idx = s2[++r] - 'a';
                ++mp2[idx];
            } else {
                // cout << "c \n";


                if (signature == mp2) {
                    return true;
                }
                idx = s2[++r] - 'a';
                ++mp2[idx];
            }
                // for (int num : signature) {cout << num << " ";} cout << "\n" <<endl;
                // for (int num : mp2) {cout << num << " ";} cout << "\n" <<endl;
        }

        if (signature == mp2) {
            return true;
        } else {
            return false;
        }

    }
};


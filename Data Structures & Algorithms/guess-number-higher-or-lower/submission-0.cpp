class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        int k = l + (r - l) / 2;
        int res;

        while ((res = guess(k)) != 0) {
            if (res == -1) {
                r = k - 1;
            } else {
                l = k + 1;
            }

            k = l + (r - l) / 2;
        }

        return k;
    }
};
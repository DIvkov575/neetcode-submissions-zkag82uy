class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (true) {
            if (n == 1) return true;
            if (visited.contains(n)) return false;

            visited.insert(n);

            int acc = 0;
            while (n) {
                acc += (n%10)*(n%10);
                n /= 10;
            }

            n = acc;
        }
        
    }
};

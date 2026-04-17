// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_set<int> visited;
//         while (true) {
//             if (n == 1) return true;
//             if (visited.contains(n)) return false;

//             visited.insert(n);

//             int acc = 0;
//             while (n) {
//                 acc += (n%10)*(n%10);
//                 n /= 10;
//             }

//             n = acc;
//         }
        
//     }
// };

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = digits_sq(n);

        while (slow != fast) {
            fast = digits_sq(digits_sq(fast));
            slow = digits_sq(slow);
        }

        return fast == 1;
    }

    int digits_sq(int n) {
        int res = 0;

        while (n) {
            int digit = n % 10;
            res += digit * digit;
            n /= 10;
        }

        return res;
    }
};

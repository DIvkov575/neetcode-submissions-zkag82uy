#include <vector>
#include <algorithm>
#include <limits>

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        // Ensure nums1 is the smaller array to get O(log min(m,n))
        const vector<int> &A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        const vector<int> &B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int m = (int)A.size();
        int n = (int)B.size();

        // Edge cases: if the smaller array is empty, median is median of B
        if (m == 0) {
            if (n == 0) return 0.0; // both empty: undefined, return 0.0 (or throw)
            if (n % 2 == 1) return (double)B[n/2];
            return ((double)B[n/2 - 1] + (double)B[n/2]) / 2.0;
        }

        int low = 0, high = m;
        const double INF_POS = std::numeric_limits<double>::infinity();
        const double INF_NEG = -INF_POS;
        int half = (m + n + 1) / 2; // left side size (handles odd/even)

        while (low <= high) {
            int i = (low + high) / 2;       // partition in A: i elements on left
            int j = half - i;              // partition in B

            // Get left/right values around the partitions, using sentinels at ends
            double Aleft  = (i == 0) ? INF_NEG : (double)A[i - 1];
            double Aright = (i == m) ? INF_POS : (double)A[i];
            double Bleft  = (j == 0) ? INF_NEG : (double)B[j - 1];
            double Bright = (j == n) ? INF_POS : (double)B[j];

            // Check partition correctness
            if (Aleft <= Bright && Bleft <= Aright) {
                // Perfect partition
                if ((m + n) % 2 == 1) {
                    return std::max(Aleft, Bleft);
                } else {
                    double leftMax = std::max(Aleft, Bleft);
                    double rightMin = std::min(Aright, Bright);
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                // Aleft too big -> move partition in A left
                high = i - 1;
            } else {
                // Bleft > Aright -> move partition in A right
                low = i + 1;
            }
        }

        // Should not reach here for valid inputs; return 0 as fallback
        return 0.0;
    }
};

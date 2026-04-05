#include <queue>
#include <vector>

class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, std::vector<int>& nums) : k(k) {
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        // Always push the new value
        minHeap.push(val);

        // Maintain heap size = k
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // The top is always the kth largest
        return minHeap.top();
    }
};

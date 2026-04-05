class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;;
    }
};




        // while (foo != prices.end()) {
        //     ++low;
        //     if (low >= max) {
        //         if (prices.end() != (foo = max_element(prices.begin(), prices.end()))) {
        //             high = distance(prices.begin(), foo);
        //         } 
        //         max = std::max(max, prices[high]-prices[low]);
        //     }

        // }

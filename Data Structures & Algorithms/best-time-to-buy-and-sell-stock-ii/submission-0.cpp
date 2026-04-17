class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lpmax = -prices[0];
        int fpmax = 0;
        for (int i = 1; i< prices.size(); ++i) {
            lpmax = max(lpmax, fpmax - prices[i]); // 1 keep long port 2 assume didnt buy at last portfolio  as if bought now instead
            fpmax = max(lpmax + prices[i], fpmax);
        }

        return max(lpmax, fpmax);
        
    }
};
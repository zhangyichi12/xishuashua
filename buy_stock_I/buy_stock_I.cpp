class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) {
            return 0;
        }

        int local = 0;
        int global = INT_MIN;

        for(int i = 1; i < prices.size(); i++) {
            local = max(0, local + prices[i] - prices[i - 1]);
            global = max(global, local);
        }

        return global;
    }
};

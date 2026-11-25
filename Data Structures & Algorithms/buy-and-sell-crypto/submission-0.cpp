class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int best = 0;

        for (int i = 1; i < (int)prices.size(); ++i) {
        // TODO 1: profit if I sell today
        int profit = prices[i] - minPrice;

        // TODO 2: keep the bigger of best and that profit
        best = max(best, profit);

        // TODO 3: keep the smaller of minPrice and today's price
        minPrice = min(minPrice, prices[i]);

        }
        return best;
    }
};

// Approach -> Tc - O(n)
// Greedy Algorithm

// suppose we buy stock at very first day and is prices increases we sell immediately. and buy again same stock on that day

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // start with buying fisrt stock
        int buy = prices[0];
        // initialise profit variable
        int profit = 0;
        // traverse the arr
        for(int i=1;i<prices.size();i++){
            // if prices is greater than buying means possible profit
            if(buy < prices[i])
                profit += prices[i] - buy;
            // else update the buy 
            buy = prices[i];
        }
        // return the profit
        return profit;
    }
};
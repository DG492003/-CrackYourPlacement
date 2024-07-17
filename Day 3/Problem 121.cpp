// Approach -> TC - O(n)
//     Initialize variables buy with the first element of the prices array and profit as 0.
//     Iterate through the prices starting from the second element.
//     Update the buy variable if the current price is lower than the current buying price.
//     Update the profit if the difference between the current price and the buying price is greater than the current profit.
//     Return the final profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // initialise the variables
        int buys = prices[0];
        int profit = 0;
        // traverse the arr
        for(int i=1;i<prices.size();i++){
            // if any lowest price encounter update buy variable
            if(prices[i] < buys)
                buys = prices[i];
            // else update profit variable if it is greater than last
            else if (prices[i] - buys > profit)
                profit = prices[i] - buys;
        }
        // return answer
        return profit;
    }
};
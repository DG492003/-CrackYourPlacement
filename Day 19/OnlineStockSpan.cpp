class StockSpanner {
private:
    stack<pair<int, int>> stack1;
public:
    StockSpanner() {}

    int next(int price) {
        int minP = 1;
        while (stack1.size() != 0 && stack1.top().first <= price) {
            minP += stack1.top().second;
            stack1.pop();
        }
        stack1.push({price, minP});
        return minP;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
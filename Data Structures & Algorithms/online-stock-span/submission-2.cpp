class StockSpanner {
public:
    stack<pair<int, int>> prev;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!prev.empty() && price >= prev.top().first){
            span += prev.top().second;
            prev.pop();
        }
        prev.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
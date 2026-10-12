class StockSpanner {
public:
int idx = -1;
stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        idx++;
        if(st.empty()){
            st.push({price,idx});
            return idx + 1;
        }
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty()){
            st.push({price,idx});
            return idx+1;
        }
        else{
            int ans = idx - st.top().second;
            st.push({price,idx});
            return ans;
        }
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
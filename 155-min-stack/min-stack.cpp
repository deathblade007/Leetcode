class MinStack {
public:
    stack<long long> st;
    int min = INT_MAX;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            min = value;
            st.push(value);
        }
        else if(value >= min){
            st.push(value);
        }
        else if(value < min){
            st.push((long long)2*value - min);
            min = value;
        }
    }
    
    void pop() {
        long long t = st.top();
        st.pop();
        if (t < min) {
            min = (long long)2 * min - t;
        }
    }
    
    int top() {
        long long t = st.top();
        if(t < min){
            return min;
        }
        else return t;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
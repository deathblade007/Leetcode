class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        // next greater element
        vector<int> ans(tem.size());
        stack<int> st;
        for(int i = tem.size()-1;i>=0;i--){
            while(!st.empty() && tem[st.top()] <= tem[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
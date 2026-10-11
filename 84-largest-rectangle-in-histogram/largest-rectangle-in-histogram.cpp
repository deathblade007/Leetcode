auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        for(int i = 0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int x = st.top();
                st.pop();
                if(st.empty()){
                    int a = heights[x] * (i);
                    ans = max(ans,a);
                }
                else{
                    int a = heights[x] * (i - st.top() - 1);
                    ans = max(ans,a);
                }
            }
            st.push(i);
        }
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(st.empty()){
                int a = heights[x] * (heights.size());
                ans = max(ans,a);
            }
            else{
                int a = heights[x] * (heights.size() - st.top() - 1);
                ans = max(ans,a);
            }
        }
        return ans;
    }
};
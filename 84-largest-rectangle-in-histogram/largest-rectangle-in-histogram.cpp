class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st1;
        stack<int> st2;
        vector<int> nse(heights.size());
        vector<int> pse(heights.size());
        for(int i = heights.size()-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                st1.push(i);
                nse[i] = heights.size();
            }
            else{
                nse[i] = st1.top();
                st1.push(i);
            }
        }
        for(int i = 0;i<heights.size();i++){
            while(!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                st2.push(i);
                pse[i] = -1;
            }
            else{
                pse[i] = st2.top();
                st2.push(i);
            }
        }
        for(auto x : nse){
            cout << x << " ";
        }
        cout << endl;
        for(auto x : pse){
            cout << x << " ";
        }
        int ans = 0;
        for(int i = 0;i<heights.size();i++){
            ans = max(ans , heights[i] * (nse[i] - pse[i] -1));
        }
        return ans;
    }
};
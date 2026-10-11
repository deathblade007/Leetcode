class Solution {
public:
    int maxRectarea(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] > height[i]) {
                int x = st.top();
                st.pop();
                if (st.empty()) {
                    int a = height[x] * (i); // height[x] * (i - (-1) -1)
                    ans = max(ans, a);
                } else {
                    int a = height[x] * (i - st.top() - 1);
                    ans = max(ans, a);
                }
            }
            st.push(i);
        }
        while (!st.empty()) {
            int x = st.top();
            st.pop();
            if (st.empty()) {
                int a = height[x] * (height.size());
                ans = max(a, ans);
            } else {
                int a = height[x] * (height.size() - st.top() - 1);
                ans = max(ans, a);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> arr(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    if(i == 0){
                        arr[i][j] = 1;
                    }
                    else{
                        arr[i][j] = arr[i-1][j] + 1;
                    }
                } else {
                    arr[i][j] = 0;
                }
            }
            ans = max(ans, maxRectarea(arr[i]));
        }
        return ans;
    }
};
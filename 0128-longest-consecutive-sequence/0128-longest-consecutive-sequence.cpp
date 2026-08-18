class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int maxlen = 0;
        int len = 1;
        int pre = *st.begin();
        for (int x : st) {
            if (x == pre + 1) {
                len++;
            } else {
                len = 1;
            }
            if (len > maxlen) {
                maxlen = len;
            }
            pre = x;
        }
        return maxlen;
    }
};
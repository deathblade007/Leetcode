class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // Smallest Element Sum
        stack<long long> st1;
        stack<long long> st2;
        vector<long long> nse(nums.size());
        vector<long long> pse(nums.size());
        for (long long i = nums.size() - 1; i >= 0; i--) {
            while (!st1.empty() && nums[st1.top()] >= nums[i]) {
                st1.pop();
            }
            if (st1.empty()) {
                nse[i] = nums.size();
                st1.push(i);
            } else {
                nse[i] = st1.top();
            }
            st1.push(i);
        }
        for (long long i = 0; i < nums.size(); i++) {
            while (!st2.empty() && nums[st2.top()] > nums[i]) {
                st2.pop();
            }
            if (st2.empty()) {
                pse[i] = -1;
                st2.push(i);
            } else {
                pse[i] = st2.top();
            }
            st2.push(i);
        }
        long long smallsum = 0;
        for (long long i = 0; i < nums.size(); i++) {
            smallsum += nums[i] * ((nse[i] - i) * (i - pse[i]));
        }

        // Large Element Sum
        stack<long long> st3;
        stack<long long> st4;
        vector<long long> nge(nums.size());
        vector<long long> pge(nums.size());

        for (long long i = nums.size() - 1; i >= 0; i--) {
            while (!st3.empty() && nums[st3.top()] <= nums[i]) {
                st3.pop();
            }
            if (st3.empty()) {
                nge[i] = nums.size();
                st3.push(i);
            } else {
                nge[i] = st3.top();
            }
            st3.push(i);
        }
        for (long long i = 0; i < nums.size(); i++) {
            while (!st4.empty() && nums[st4.top()] < nums[i]) {
                st4.pop();
            }
            if (st4.empty()) {
                pge[i] = -1;
                st4.push(i);
            } else {
                pge[i] = st4.top();
            }
            st4.push(i);
        }
        long long greatsum = 0;
        for (long long i = 0; i < nums.size(); i++) {
            greatsum += nums[i] * ((nge[i] - i) * (i - pge[i]));
        }
        return greatsum - smallsum;
    }
};
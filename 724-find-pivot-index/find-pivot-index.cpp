class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1;
        vector<int> pre;
        vector<int> suf;
        pre.push_back(0);
        int presum = 0;
        int totalsum = nums[nums.size()-1];
        for(int i =0;i<nums.size()-1;i++){
            presum = nums[i] + presum;
            totalsum += nums[i];
            pre.push_back(presum);
        }
        for(int i = 0;i<nums.size();i++){
            totalsum -= nums[i];
            suf.push_back(totalsum);
        }
        for(int i = 0;i<nums.size();i++){
            if(pre[i] == suf[i]) return i;
        }
        return -1;
    }
};
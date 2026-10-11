class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            ans.push_back(nums[i] + sum);
            sum += nums[i];
        }
        return ans;
    }
};
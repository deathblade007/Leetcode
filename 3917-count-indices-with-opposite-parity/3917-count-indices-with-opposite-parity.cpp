class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        if(nums.size() == 1) return {0};
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n-1;i++){
            if(nums[i]%2 == 0){
                int cnt = 0;
                for(int j = i+1;j<n;j++){
                    if(nums[j]%2 == 1) cnt++;
                }
                ans.push_back(cnt);
            }
            else{
                int cnt = 0;
                for(int j = i+1;j<n;j++){
                    if(nums[j]%2 == 0) cnt++;
                }
                ans.push_back(cnt);
            }
        }
        ans.push_back(0);
        return ans;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int lm = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                lm++;
                if(lm > max){
                    max = lm;
                }
            }
            else{
                lm = 0;
            }
        }
        return max;
    }
};
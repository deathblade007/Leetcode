class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        vector<int> ans;
        for(auto x : nums1){
            mp1[x]++;
        }
        for(auto x : nums2){
            mp2[x]++;
        }
        for(auto [key , value] : mp1){
            if(mp2.find(key) != mp2.end()){
                for(int i = 0;i<min(value,mp2[key]);i++){
                    ans.push_back(key);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void sub(vector<int> arr, vector<int>& al, int i, int k, int& sum) {
        if (i == arr.size() || sum > k) {
            return;
        }
        if (sum == k) {
            ans.push_back(al);
            return;
        } else {
            al.push_back(arr[i]);
            sum += arr[i];
            sub(arr, al, i, k, sum);
            al.pop_back();
            sum -= arr[i];
            sub(arr, al, i + 1, k, sum);
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> al;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        sub(candidates, al, 0, target, sum);
        return ans;
    }
};
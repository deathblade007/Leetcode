class Solution {
public:
    bool check(vector<int>& arr) {
        int p = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) {
                continue;
            } else {
                p = i;
                break;
            }
        }
        reverse(arr.begin(), arr.begin() + p);
        reverse(arr.begin() + p, arr.end());
        reverse(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1])
                continue;
            else
                return false;
        }
        return true;
    }
};
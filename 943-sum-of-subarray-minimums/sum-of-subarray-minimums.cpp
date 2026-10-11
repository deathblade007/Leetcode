class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        vector<int> nse(arr.size());
        vector<int> pse(arr.size());
        stack<pair<int,int>> st1;
        stack<pair<int,int>> st2;
        for(int i = arr.size()-1;i>=0;i--){
            while(!st1.empty() && st1.top().first >= arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                nse[i] = arr.size();
            }
            else{
                nse[i] = st1.top().second;
            }
            st1.push({arr[i],i});
        }

        for(int i = 0;i<arr.size();i++){
            while(!st2.empty() && st2.top().first > arr[i]){
                st2.pop();
            }
            if(st2.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st2.top().second;
            }
            st2.push({arr[i],i});
        }
        int ans = 0;
        for(int i = 0 ;i<arr.size();i++){
            ans = (ans + (1LL * (nse[i] - i) * (i - pse[i]))*arr[i]) % mod;
            ans = ans % mod;
        }
        return (ans % mod);
    }
};
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        queue<pair<char,int>> q;
        for(int i = 0;i<s.size();i++){
            mp[s[i]]++;
            q.push({s[i],i});

            while(!q.empty() && mp[q.front().first] > 1){
                q.pop();
            }
        }
        if(q.empty()){
            return -1;
        }
        else return q.front().second;
    }
};
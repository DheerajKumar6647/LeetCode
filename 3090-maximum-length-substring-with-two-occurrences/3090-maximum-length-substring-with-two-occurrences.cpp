class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
       unordered_map<char,int>mp;
       int mx = INT_MIN;
       int i=0;
       for(int j=0; j<n; j++){
        mp[s[j]] ++;
        while(mp[s[j]] > 2){
            mp[s[i]]--;
            i++;
        }
        mx = max(mx , j-i+1);
       }
       return mx;
    }
};
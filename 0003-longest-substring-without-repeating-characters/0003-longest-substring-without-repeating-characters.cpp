class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int idx = 0;
       int mx = 0;
       unordered_map<char , int>mp;
       for(int i=0; i<n; i++){
        if(mp.count(s[i])){
            
            while(s[idx] != s[i]){
                mp.erase(s[idx]);
                idx++;
            }
            
            idx++;
         
        }
        else mp[s[i]]++;
        mx = max(mx , i - idx+1);
       } 
       return mx;
    }
};
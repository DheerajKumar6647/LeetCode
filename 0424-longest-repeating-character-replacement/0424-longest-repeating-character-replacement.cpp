class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxFreq = INT_MIN;
        int mxlen = 0;
        unordered_map<char , int>mp;
        while(right < n){
            mp[s[right]]++;
            maxFreq = max(maxFreq , mp[s[right]]);
            
           

            while(right-left+1 - maxFreq > k){
                mp[s[left]]--;
                left++;
            }
            mxlen = max(mxlen , right-left+1) ;
            right++;
        }
        return mxlen;
    }
};
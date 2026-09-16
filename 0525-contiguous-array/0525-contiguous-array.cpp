class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0] = (nums[0] == 0)? -1 : 1;
        for(int i=1; i<n; i++){
            if(nums[i] == 0){
                pre[i] = pre[i-1] - 1;
            }
            else pre[i] = pre[i-1] + 1;
            
        }
        int mx = 0;
        int ans = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(mp.count(pre[i])){
                mx = i - mp[pre[i]];
                ans = max(ans , mx);
            }
            else mp[pre[i]] = i;

        }
        return ans;
    }
};
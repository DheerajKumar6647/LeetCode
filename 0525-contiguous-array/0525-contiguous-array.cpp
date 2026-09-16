class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int ans = 0;
        int sum = 0;
        unordered_map<int,int>mp;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) sum--;
            if(nums[i] == 1) sum++;
            if(mp.count(sum)){
                mx = i - mp[sum];
                ans = max(ans , mx);
            }
            else mp[sum] = i;

        }
        return ans;
    }
};
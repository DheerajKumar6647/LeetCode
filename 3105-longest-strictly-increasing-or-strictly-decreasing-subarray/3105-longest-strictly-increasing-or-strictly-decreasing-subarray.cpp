class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int inc = 1;
        int dec = 1;
        int cnt = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] > nums[i+1]) cnt++;
            else cnt = 1;
            dec = max(cnt , dec);
        }
        cnt = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] < nums[i+1]) cnt++;
            else cnt = 1;
            inc = max(cnt , inc);
        }
        return max(inc , dec);
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long count = 0;
        long long len = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                len ++;
                count += len;
            }
            else len = 0;
        }
        return count;
    }
};
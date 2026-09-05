class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>preMax(n);
        vector<int>sufMin(n);
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] < mx){
                preMax[i] = mx;
            }
            else{
                preMax[i] = nums[i];
                mx = nums[i];
            }
        }
        int mn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            if(nums[i] > mn){
                sufMin[i] = mn;
            }
            else {
                sufMin[i] = nums[i];
                mn = nums[i];
            }
        }
        
        for(int i=0; i<n; i++){
            int diff = preMax[i] - sufMin[i];
            if(diff <= k){
                return i;
            }
        }
        
        return -1;
    }
};
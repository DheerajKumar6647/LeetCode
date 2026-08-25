class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int min = INT_MAX;
        int mx = INT_MIN;
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            if(nums[i]%k == 0){
                st.insert(nums[i]/k);
                if(nums[i]/k > mx) mx = nums[i]/k;
            }
        }
        int i=1;
        for(i=1; i<=mx; i++){
            if(!st.count(i)){
                return k*i;
            }
        }
        return k*(i);
    }
};
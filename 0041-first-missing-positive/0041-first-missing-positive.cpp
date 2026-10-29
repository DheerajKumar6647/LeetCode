class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for (int i=0; i<n; i++){
            if(nums[i] > 0){
                st.insert(nums[i]);
            }
        } 
        int idx = 1;  
        for(auto x : st){
            if(x != idx){
                return idx;
            }
            idx++;
        }
        return idx;
    }
};
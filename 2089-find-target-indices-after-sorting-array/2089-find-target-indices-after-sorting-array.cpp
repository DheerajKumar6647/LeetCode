class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>arr;
        sort(nums.begin() , nums.end());
        int i=0; 
        while(i<n && nums[i] != target){
            i++;
        }
        while(i<n && nums[i] == target){
            arr.push_back(i);
            i++;
        }
        return arr;  
    }
};
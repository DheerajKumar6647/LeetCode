class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = *min_element(nums.begin() , nums.end());
        unordered_set<int>st;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        return sum - (long long)n*mn;
    }
};
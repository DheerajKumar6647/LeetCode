class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int score = 0;
        int maxScore = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            score += nums[i];
            if (!st.count(nums[i])) {

                st.insert(nums[i]);
            } else {
                while (nums[j] != nums[i]) {
                    score -= nums[j];
                    st.erase(nums[j]);
                    j++;
                }
                score -= nums[j];
            
                j++;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};
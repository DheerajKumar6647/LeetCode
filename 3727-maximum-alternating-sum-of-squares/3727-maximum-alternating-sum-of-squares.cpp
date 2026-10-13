class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto &x: nums){
            x = abs(x);
        }
        sort(nums.begin() , nums.end());
        int i=0 , j=n-1;
        while(i<=j){
            sum += 1LL*(nums[j]*nums[j]);
            if(j!=i) sum -= 1LL*(nums[i]*nums[i]);
            j--;
            i++;
        }
        return sum;
    }
};
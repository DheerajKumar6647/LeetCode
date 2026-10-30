class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int neg = 0;
        int zero = 0;
        sort(nums.begin() , nums.end());
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(nums[i] < 0) neg++;  
            if(nums[i] == 0) zero++;            
        }
        for(int i=0; i<min(neg,k); i++){
            sum += 2*abs(nums[i]);
            nums[i] = abs(nums[i]);
        }
        if(neg > 0) k -= min(k , neg);
        if(zero > 0) return sum;
        if(k>0 && k%2 == 0) return sum;
        int mn = *min_element(nums.begin() , nums.end());
        if(k>0 && k%2 != 0){
            sum -= 2*mn;
            return sum;
        }
        return sum;
    }
};
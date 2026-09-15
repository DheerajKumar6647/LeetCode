class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int right = 0;
        int left = 0;
        int odds = 0;
        int evens = 0;
        int count = 0;
        while(right < n){
            if(nums[right]%2 != 0){
                odds ++;
                evens = 0;
            }
            
            if(odds > k){
                while(odds>k){
                    if(nums[left]%2 != 0){
                        odds --;
                    }
                    left ++;
                }
            }
            if(odds == k){
                while(left < right && nums[left]%2 == 0){
                    evens ++;
                    left ++;
                }
                count += evens+1;
            }
            right ++;

        }
        return count;
    }
};
class Solution {
public:
    int countMin(vector<int>&arr , int mid){
        int n = arr.size();
        int count = 0;
        int j=0;
        for(int i=0; i<n; i++){
            while(j<n && arr[j] - arr[i] <= mid){
                j++;
            }
            count += j-i-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[n-1] - nums[0];
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            int count = countMin(nums , mid);
            if(count >= k){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    }
};
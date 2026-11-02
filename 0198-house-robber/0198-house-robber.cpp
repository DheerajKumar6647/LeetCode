class Solution {
public:
    int ftd(vector<int> arr , int i , vector<int>& dp){
        
        if(i == arr.size()-1) return arr[i];
        if(i == arr.size()-2) return max(arr[i] , arr[i+1]);
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(arr[i] + ftd(arr,i+2 , dp) , 0+ftd(arr , i+1, dp));
    }
    int fbu(vector<int>& dp){
        int n = dp.size();
        if(n==1) return dp[0];
        if(n==2) return max(dp[0] , dp[1]);
        dp[n-2] = max(dp[n-1] , dp[n-2]);
        for(int i=n-3; i>=0; i--){
            dp[i] = max(dp[i+1] , dp[i] + dp[i+2]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        //for Top Down

        // vector<int>dp(nums.size() , -1);
        // return ftd(nums , 0 , dp);

        //For Bottom Up
        return fbu(nums);
    }
};
class Solution {
public:
    int helper(int i , int j, int er , int ec, vector<vector<int>>& dp){
        if(i == er && j == ec) return 1;
        if(i > er || j > ec) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(i+1,j,er,ec,dp)+helper(i,j+1,er,ec,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n,-1));
        return helper(0,0,m-1,n-1,dp);
    }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        int len = bookings.size();
        vector<int>ans(n , 0);
        for(int i=0; i<len; i++){
            for(int j=bookings[i][0]-1; j<bookings[i][1]; j++){
                ans[j] += bookings[i][2];
            }
        }
        return ans;
    }
};
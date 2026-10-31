class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , [](vector<int> &a , vector<int>&b){
            return a[0] < b[0];
        });
        int cnt = 0;
        int i = 0;
        vector<int>prev = intervals[i];
        for(int j=1; j<n; j++){
            
            vector<int>curr = intervals[j];
            if(curr[0] < prev[1]){
                cnt++;
                prev[1] = min(prev[1] , curr[1]);
            }
            else{
                prev[1] = curr[1];
            }

        }
        return cnt;
    }
};
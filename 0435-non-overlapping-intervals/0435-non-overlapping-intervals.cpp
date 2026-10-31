class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , [](vector<int> &a , vector<int>&b){
            return a[1] < b[1];
        });
        int cnt = 0;
        int i = 0;
        for(int j=1; j<n; j++){
            vector<int>prev = intervals[i];
            vector<int>curr = intervals[j];
            if(curr[0] < prev[1]){
                cnt++;
            }
            else{
                i = j;
            }

        }
        return cnt;
    }
};
class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , cmp);
        vector<vector<int>>ans;
        int i = 0 ;
        int j = 1;
        while(j < n){
            if(intervals[j][0] <= intervals[i][1]){
                intervals[i][1] = max(intervals[i][1] , intervals[j][1]);
                j++;
            }
            else{
                ans.push_back(intervals[i]);
                i = j;
                j++;
                
            }
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};
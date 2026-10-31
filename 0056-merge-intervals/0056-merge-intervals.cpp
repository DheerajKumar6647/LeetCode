class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end() , cmp);
        vector<vector<int>>ans;
        ans.push_back(intervals[n-1]);
        for(int i=n-2 ; i>=0; i--){
            //vector<int>lastPos = ans[ans.size()-1];
            vector<int>curr = intervals[i];
            if(intervals[i][1] >= ans[ans.size()-1][0]){
                ans[ans.size()-1][0] = min(curr[0] , ans[ans.size()-1][0]);
                ans[ans.size()-1][1] = max(curr[1] , ans[ans.size()-1][1]);
    
            }
            else{
                ans.push_back(intervals[i]);
            }
            
        }

        
        return ans;
    }
};
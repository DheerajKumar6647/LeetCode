class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , [](vector<int> &a , vector<int>&b){
            return a[1] < b[1];
        });
        int n = points.size();
        int cnt = 0;
        int j = 0;
        vector<int>prev = points[j];
        for(int i=1; i<n; i++){
            vector<int>curr = points[i];
            if(curr[0] <= prev[1]){
                cnt++;
                
            }
            else{
                prev[0] = min(prev[0], curr[0]); 
                prev[1] = max(prev[1], curr[1]);
            }
        }
        return n-cnt;
    }
};
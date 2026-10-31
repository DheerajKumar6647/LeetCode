class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end() , [](vector<int> &a , vector<int>&b){
            return a[0] < b[0];
        });
        int n = points.size();
        int cnt = 0;
        int j = 0;
        vector<int>prev = points[j];
        for(int i=1; i<n; i++){
            vector<int>curr = points[i];
            if(curr[0] <= prev[1]){
                cnt++;
                prev[1] = min(prev[1] , curr[1]);
            }
            else{
                prev = curr; 
            }
        }
        return n-cnt;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int , pair<int,int>>>pq;

        for(auto ele : points){
            int dist = (ele[0]*ele[0] + ele[1]*ele[1]);
            pq.push({dist , {ele[0],ele[1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>>ans(k , vector<int>(2));
        int idx = 0;
        while(!pq.empty()){
            ans[idx][0] = pq.top().second.first;
            ans[idx][1] = pq.top().second.second;
            pq.pop();
            idx++;
        }
        return ans;
    }
};
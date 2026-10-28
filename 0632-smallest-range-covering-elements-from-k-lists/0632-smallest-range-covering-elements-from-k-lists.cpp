class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int,int>> ,
        vector<pair<int, pair<int,int>> > ,
        greater<pair<int, pair<int,int>>> >pq;
        int mx = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            mx = max(mx,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        int mn = pq.top().first;
        int start = mn , end = mx;
        
        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if(col == nums[row].size()-1) break;

            pq.pop();
            pq.push({nums[row][col+1],{row,col+1}});
            mx = max(mx , nums[row][col+1]);
            mn = pq.top().first;

            if(mx-mn < end-start){
                start = mn;
                end = mx;
            }
            // else if(mx-pq.top().first == ans[2]){
            //     if(ans[0] > pq.top().first){
            //         ans[0] = pq.top().first;
            //         ans[1] = mx;
            //     }
            // }
        
        }
        return {start , end};
    }
};
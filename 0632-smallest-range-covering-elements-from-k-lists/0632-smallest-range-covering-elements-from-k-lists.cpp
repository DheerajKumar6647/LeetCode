class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int,int>> ,
        vector<pair<int, pair<int,int>> > ,
        greater<pair<int, pair<int,int>>> >pq;
        int mx = INT_MIN;
        vector<int>ans(3);
        for(int i=0; i<nums.size(); i++){
            mx = max(mx,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        ans[0] = pq.top().first;
        ans[1] = mx;
        ans[2] = ans[1] - ans[0];
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        while(y < nums[x].size()-1){
            // x = pq.top().second.first;
            // y = pq.top().second.second;
            //if(y == nums[x].size()-1) break;
            
            mx = max(mx , nums[x][y+1]);

            pq.pop();
            pq.push({nums[x][y+1],{x,y+1}});
            if(mx-pq.top().first < ans[2]){
                ans[0] = pq.top().first;
                ans[1] = mx;
                ans[2] = ans[1] - ans[0];
            }
            else if(mx-pq.top().first == ans[2]){
                if(ans[0] > pq.top().first){
                    ans[0] = pq.top().first;
                    ans[1] = mx;
                }
            }
            x = pq.top().second.first;
            y = pq.top().second.second;
        
        }
        ans.pop_back();
        return ans;
    }
};
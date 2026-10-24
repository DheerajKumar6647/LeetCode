class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        for(auto x : mp){
            pq.push({x.second , -x.first});
        }

        vector<int>ans;
        while(!pq.empty()){
            int idx = pq.top().first;
            int val = -pq.top().second;
            pq.pop();
            
            for(int i=0; i<idx; i++){
                ans.push_back(val);

            }
            
        }
       
        return ans;
    }
};
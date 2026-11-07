class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int n = items1.size();
        int m = items2.size();
        map<int , int>mp;
        for(int i=0; i<n; i++){
            mp[items1[i][0]] += items1[i][1];
        }
        for(int i=0; i<m; i++){
            mp[items2[i][0]] += items2[i][1];
        }
        vector<vector<int>>ans;
        
        for(auto x : mp){
          ans.push_back({x.first , x.second});
        }
        return ans;
    }
};
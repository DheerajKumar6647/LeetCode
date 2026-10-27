class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector <string>temp = strs ;
        for(int i=0; i<n; i++){
            sort(temp[i].begin() , temp[i].end());
        }
        
        vector<vector<string>>ans;
        int idx = -1;
        unordered_map<string , int>mp;
        for(int i=0; i<n; i++){
            if(mp.empty() || !mp.count(temp[i])){
                vector<string>ele;
                idx ++;
                mp[(temp[i])] = idx;
                ele.push_back(strs[i]);
                ans.push_back(ele);
            }
            else{
                ans[mp[temp[i]]].push_back(strs[i]);
            }
        }
        return ans;
    }
};
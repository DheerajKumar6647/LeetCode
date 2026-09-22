class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        
        int distEle = st.size();

        int left = 0;
        int count = 0;
        unordered_map<int,int>mp;
        
        for(int right = 0; right<n; right++){
            mp[nums[right]] ++;
            while(mp.size() == distEle){
                count += n-right;
                mp[nums[left]] --;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left ++;
            }
        }
        return count ;
    }
};
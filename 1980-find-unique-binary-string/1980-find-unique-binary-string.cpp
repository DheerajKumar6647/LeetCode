class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        int i = 0;
        while(i<n){
            if(nums[i][i] == '0') ans += "1";
            else ans += "0";
            i++;
        }
        return ans;
    
    }
};
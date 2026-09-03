class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minOdd = INT_MAX;
        for(int x : nums1){
            if(x%2 != 0) minOdd = min(minOdd , x);
        }
        if(minOdd == INT_MAX) return true;
        bool flag1 = true;
        for(int i=0; i<n; i++){
            if(nums1[i] %2 == 0 && nums1[i] < minOdd){
                flag1 = false; 
            }
        }
        
        return flag1;
    }
};
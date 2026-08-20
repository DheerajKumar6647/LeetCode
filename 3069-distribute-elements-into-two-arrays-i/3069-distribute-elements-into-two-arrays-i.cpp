class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int i = 0;
        arr1.push_back(nums[i]);
        if(i < nums.size()) arr2.push_back(nums[i+1]);
        i+=2;
     
        while(i<nums.size()){
            if(arr1[arr1.size()-1] > arr2[arr2.size()-1]){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
            i++;
        }
        for(int k=0; k<arr2.size(); k++){
            arr1.push_back(arr2[k]);
        }
        return arr1;
    }
};
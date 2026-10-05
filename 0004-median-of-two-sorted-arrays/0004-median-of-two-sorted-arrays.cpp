class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int a = n-1;
        int b = m-1;
        int c = n+m-1;
        vector<int>ans(n+m ,0);

        while(a>=0  && b>=0){
            if(nums1[a] > nums2[b]){
                ans[c] = nums1[a];
                a--;
            }
            
            else{
                ans[c] = nums2[b];
                b--;
            }
            c--;
        }
        while(a>=0){
                ans[c] = nums1[a];
                a--;
                c--;
        }
        while(b>=0){
            ans[c] = nums2[b];
            b--;
            c--;
        }
        int l = ans.size();
        if(l%2 == 0){
            return   ((double)ans[l/2]+ ans[(l-1)/2])/2.0;
             
        }
        else{
            return ans[l/2];
        }
    }
};
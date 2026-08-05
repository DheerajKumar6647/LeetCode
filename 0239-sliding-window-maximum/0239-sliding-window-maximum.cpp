class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int>st;
        vector<int>ngi(n);
        ngi[n-1] = n;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        int j = 0;
        
        vector<int>ans;
        for(int i=0; i<(n-k+1); i++){
            if(j<i) j=i;
            int mx = nums[j];
            while(j < i+k){
                mx = nums[j];
                if(ngi[j] >= i+k)break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
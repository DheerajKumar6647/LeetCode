class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        vector<int>nge(n , 0);
        nge[n-1] = 0;
        st.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            int ans = 0;
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
                ans++;
            }
            if(!st.empty())ans ++;
            nge[i] = ans;
            st.push(arr[i]);
        }
        return nge;
    }
};
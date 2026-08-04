class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
       vector<int>psi(n);
       stack<int>st;
       psi[0] = -1;
       st.push(0);
       for(int i=1; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) psi[i] = -1;
        else psi[i] = st.top();
        // psi[i] = i - psi[i];
        st.push(i);
       }
        stack<int>st1;
        vector<int>nsi(n);
        nsi[n-1] = n;
        st1.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(st1.size()>0 && heights[st1.top()] >= heights[i])st1.pop();
            if(st1.empty()) nsi[i] = n;
            else nsi[i] = st1.top();
            // nsi[i] = i - nsi[i];
            st1.push(i); 
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = (nsi[i]-psi[i]-1)*heights[i];
        }
        return *max_element(ans.begin() , ans.end());
    }
};
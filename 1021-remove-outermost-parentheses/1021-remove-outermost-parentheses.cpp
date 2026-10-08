class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0;
        string ans = "";
        int n = s.size();
        stack<int> st;
        for (int right = 0; right < n; right++) {
            if (s[right] == '('){
                st.push(s[right]);
            }
            if(s[right] == ')'){
                if(st.size() == 1){
                    ans += s.substr(left+1 , right-left-1);
                    left = right+1;
                    st.pop();
                }
                else st.pop();
            }
        }
        return ans;
    }
};
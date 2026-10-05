class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int>st;
        st.push(0);
       
        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else {
                int pre = st.top();
                st.pop();
                int score = (pre == 0)? 1 : 2*pre;
                st.top() += score;
            }
        }
        return st.top();
    }
};
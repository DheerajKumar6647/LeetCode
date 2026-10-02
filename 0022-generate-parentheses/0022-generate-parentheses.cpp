class Solution {
public:
    void par(int n , int open , int close , string s , vector<string>&ans){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            par(n , open+1 , close , s+"(" , ans);
        }
        if(close < open){
            par(n , open , close+1 , s+")" , ans);
        }
    } 
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        
        par(n , 0, 0 , "" , ans);
        return ans;
    }
};
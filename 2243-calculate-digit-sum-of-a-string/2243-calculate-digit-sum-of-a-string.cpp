class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size() > k){
            string helper = "";
            for(int i=0; i<s.size(); i+=k){
                int n = 0;
                int j = 0;
                while(j<k && i+j < s.size()){
                    n += (s[i+j]-'0');
                    j++;
                }
                helper += to_string(n);
            }
            cout<<helper<<" ";
            s = helper;
        } 
       return s;
    }
};
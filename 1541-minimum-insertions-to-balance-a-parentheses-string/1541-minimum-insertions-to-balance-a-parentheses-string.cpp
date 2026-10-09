class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
       
        int need = 0;
        int open = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open ++;
            }
            else{
                if(i+1 < n && s[i+1] == ')'){
                    i++;
                    if(open > 0){
                        open--;
                    }
                    else need ++;
                }
                else{
                    if(open > 0){
                        open --;
                        need ++;
                    }
                    else need += 2;
                } 
            }
        }
        need += 2*open;
        return need;
        
    }
};
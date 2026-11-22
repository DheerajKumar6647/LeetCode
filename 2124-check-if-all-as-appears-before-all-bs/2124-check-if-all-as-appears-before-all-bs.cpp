class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        for(char x : s){
            if(x == 'b') flag = false;
            if(x == 'a' && flag == false ){
                return false;
            }
        }
        return true;
    }
};
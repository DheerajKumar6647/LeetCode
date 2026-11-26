class Solution {
public:
    bool canAliceWin(int n) {
        int alice = 10;
        int bob = 9;
        while(n >= alice){
            n -= alice;
            alice = bob-1;
            if(n >= bob){
                n -= bob;
                bob = alice -1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
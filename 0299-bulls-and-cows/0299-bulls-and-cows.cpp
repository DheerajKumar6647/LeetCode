class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]) bulls++;
            else {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto x : mp1){
            if(mp2.count(x.first)) cows += min(mp1[x.first] ,mp2[x.first]);
        }
        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};
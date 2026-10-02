class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        int cows = 0;
        int freq[10] = {0};
        for(int i=0; i<n ; i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                freq[secret[i] - '0']++;
            }
        }
        for(int i=0; i<n; i++){
            if(guess[i] != secret[i]){
                if(freq[guess[i] - '0'] > 0){
                    cows++;
                    freq[guess[i] - '0']--;
                }
            }
        }
        
        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;
    }
};
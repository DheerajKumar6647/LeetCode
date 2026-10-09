class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int left = 0;
        int vowel = 0;

        for(int i=0; i<n; i++){
            
            while(i<n && i-left < k){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    vowel ++;
                }
                i++;
            }
            ans = max(ans , vowel);
            if(ans == k) return ans;

            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u'){
                vowel--;    
            }
            left++;
            i--;

        }
        return ans;
    }
};
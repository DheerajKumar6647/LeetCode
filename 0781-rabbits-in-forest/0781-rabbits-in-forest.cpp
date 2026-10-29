class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            int x = answers[i];
            if(!mp.count(x+1)){
                ans += x+1;
                if(x == 0) continue;
                else mp[x+1]++;
            }
            else{
                mp[x+1]++;
                if(mp[x+1] == x+1){
                    mp.erase(x+1);
                }
            }
        }
        return ans;
    }
};
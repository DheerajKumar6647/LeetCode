class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        int ans = 0;
        sort(answers.begin() , answers.end());
        for(int i=0; i<n; i++){
            ans += answers[i]+1;
            int limit = answers[i];
            for(int j=0; j<limit; j++){
                if(i<n-1 && answers[i] == answers[i+1]){
                    i++;
                }
            }
        }
        return ans;
    }
};
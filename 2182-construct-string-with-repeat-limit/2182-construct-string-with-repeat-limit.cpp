class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        unordered_map<char , int>mp;
        for(char ch : s){
            mp[ch]++;
        } 
        priority_queue<pair<char,int>>pq;
        for(auto x : mp){
            pq.push({x.first , x.second});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().second;
            if(freq > repeatLimit){
                for(int i=0; i<repeatLimit; i++){
                    ans += pq.top().first;
                }
                freq -= repeatLimit;
                pair<char , int>temp = {pq.top().first , freq};
                pq.pop();
                if(pq.empty()) return ans;
                else{
                    ans += pq.top().first;
                    pair<char , int>temp2 = pq.top();
                    pq.pop();
                    temp2.second--;
                    if(temp2.second > 0){
                        pq.push(temp2);
                    }
                    pq.push(temp);
                    
                }
            }
            else{
                for(int i=0; i<freq; i++){
                    ans += pq.top().first;
                }
                pq.pop();
            }
        }
        return ans;
    }
};
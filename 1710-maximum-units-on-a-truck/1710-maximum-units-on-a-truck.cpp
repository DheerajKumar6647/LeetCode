class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<n; i++){
            pq.push({boxTypes[i][1] , boxTypes[i][0]});
        }
        int ans  = 0;
        while(truckSize > 0 && !pq.empty()){
            int second =pq.top().second ;
            int first = pq.top().first;
            if(truckSize > 0){
                ans += first*min(second , truckSize);
                truckSize -= min(second , truckSize);
                pq.pop();
            }
        }
        return ans;
    }
};
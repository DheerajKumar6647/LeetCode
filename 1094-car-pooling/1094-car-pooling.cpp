class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<int>arr(1001 , 0);
        for(auto trip : trips){
            int pass = trip[0];
            int start = trip[1];
            int end = trip[2];
             
            arr[start] += pass;
            arr[end] -= pass;

        }
        int cap = 0;
        for(int i=0; i<=1000; i++){
            cap += arr[i];
            if(cap > capacity) return false;
            
        }
        return true;

    }
};
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>arr;
        arr.push_back(1);
        arr.push_back(1);

        for(int i=2; i<=k; i++){
            int ele = arr[i-1] + arr[i-2];
            arr.push_back(ele);
            if(arr[i] >= k) break;
        }
        int idx = arr.size()-1;
        int cnt = 0;
        
        while(idx >= 0){
            if(arr[idx] <= k){
                k -= arr[idx];
                cnt++;
            }
            idx--;
        }
        return cnt;
    }
};
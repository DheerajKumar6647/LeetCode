class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long even = 1, odd = 0;
        long long sum = 0 ,ans = 0;
        int mod = 1e9+7;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum %2 == 0){
                even++;
                ans += odd;
            }
            else{
                odd++;
                ans+= even;
            }
            ans%=mod;
        }
        return ans;
    }
};
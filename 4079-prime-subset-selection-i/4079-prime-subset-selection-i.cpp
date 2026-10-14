class Solution {
public:
    bool is_prime(long long n){
        if(n<2) return false;
        for(long long i=2; i*i<=n; i++){
            if(n%i == 0) return false; 
        }
        return true;
    }
    vector<int> maxPrimes(int n, int s) {
        vector<int>ans;
        long long sum = 0;
        if(s<2 || n<2) return {};
        long long start = 2;
        while(sum <= s && start <= n){
            if(is_prime(start)){
                if(sum +start > s) return ans;
                sum += start;
                ans.push_back(start);
            }
            start++;
        }
        return ans; 
    }
};
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long temp = min(need1 , need2);
        long long ans = temp*min(1LL*costBoth , 1LL*cost1 + cost2);
        need1 -= temp;
        need2 -= temp;
        ans += 1LL*need1*min(cost1 , costBoth);
        ans += 1LL*need2*min(cost2 , costBoth);
        return ans;
    }
};
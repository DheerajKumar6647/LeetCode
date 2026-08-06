class Solution {
public:
    bool productSum(int n, int t) {
        int pr = 1;
        while (n > 0) {
            pr *= (n % 10);
            n /= 10;
        }
        if (pr % t == 0) {
            return true;
        } else
            return false;
    }
    int smallestNumber(int n, int t) {
        if (productSum(n, t))
            return n;
        int i = n + 1;
        while (i < n + 10) {
            if (productSum(i, t)) {
                return i;
            }
            i++;
        }
        return n;
    }
};
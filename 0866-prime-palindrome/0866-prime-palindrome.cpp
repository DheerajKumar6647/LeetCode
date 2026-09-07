class Solution {
public:
    bool is_prime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int makePal(int n) {
        int real = n;
        int x = n / 10;
        while (x > 0) {
            real = real * 10 + (x % 10);
            x /= 10;
        }
        return real;
    }
    int primePalindrome(int n) {
        if (n <= 7) {
            for (int i = n; i <= 7; i++) {
                if (is_prime(i)) {
                    return i;
                }
            }
        }
        if (n <= 11) {
            return 11;
        }
        for (int i = 1;; i++) {
            int pal = makePal(i);
            if (pal >= n && is_prime(pal)) {
                return pal;
            }
        }
        return 0;
    }
};
#include<iostream>

class Solution {
public:
    int count_sum(long long n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        if (count_sum(n) <= target) return 0;

        long long add = 0;
        long long base = 10;

        while (count_sum(n) > target) {
            long long rem = n % base;
            long long delta = (base - rem) % base;

            add += delta;
            n += delta;
            base *= 10;
        }

        return add;
    }
};

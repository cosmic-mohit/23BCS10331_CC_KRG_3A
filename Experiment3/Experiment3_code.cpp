#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = min(a, b);
        long long high = (long long)n * min(a, b);
        long long L = lcm(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long count =
                mid / a +
                mid / b -
                mid / L;

            if (count < n)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

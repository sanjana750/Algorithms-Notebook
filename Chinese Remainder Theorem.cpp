#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Extended Euclidean Algorithm
ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) {
        ll d = euclid(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
    x = 1;
    y = 0;
    return a;
}

// Chinese Remainder Theorem (m and n must be coprime)
template<class Z>
Z chinese(Z a, Z m, Z b, Z n) {
    Z x, y;
    euclid(m, n, x, y);

    Z mod = m * n;
    Z ret = (a * (y % m + m) % m * n +
             b * (x % n + n) % n * m) % mod;

    return ret;
}

// Chinese Remainder Theorem for non-coprime moduli
template<class Z>
Z chinese_common(Z a, Z m, Z b, Z n) {
    Z d = std::gcd(m, n);

    b = b - a;
    b %= n;
    if (b < 0) b += n;

    if (b % d != 0) return -1; // No solution

    return d * chinese(Z(0), m / d, b / d, n / d) + a;
}

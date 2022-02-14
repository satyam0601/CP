#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define For(i,s,n) for(ll i = s;i <= n;i++)
#define repi(n) for (int i = 0; i < n; i++)
#define repj(n) for (int j = 0; j < n; j++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define t_cases ll t; cin >> t; while(t--)
#define debug(a) cout << a << "\n"

using namespace std;

ull nCr(ull n, ull r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (n * nCr(n - 1, r - 1) / r) % MOD;
}

ll powermod(ll a, ll p) {
    a = a % MOD;
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        p = p >> 1;
    }
    return res;
}

ull invmod(ull a) {
    return powermod(a, MOD - 2);
}

ull nCrmod(ull n, ull r) {
    if (n < r) return 0;
    if (r == 0 or n == r) return 1;

    ull fact[n + 1]; fact[0] = fact[1] = 1;
    for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * (i % MOD)) % MOD;

    ull cnr = ((fact[n] * invmod(fact[r]) % MOD) * invmod(fact[n - r])) % MOD;
    return cnr;
}


ll gcd(ll a, ll b) {
    if (a == 0) return b;

    return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

bool is_primo(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    ll s = sqrt(n);
    for (int i = 2; i <= s + 1; i++) if (n % i == 0) return false;
    return true;
}

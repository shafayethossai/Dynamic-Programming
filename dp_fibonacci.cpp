#include <bits/stdc++.h>
using namespace std;

#define    ll long long
#define    mod 10000007

int basicIO(ll a, ll b, ll c, ll d, ll e, ll f, ll n, vector<ll> &dp) {
    if (n == 0) return a % mod;
    if (n == 1) return b % mod;
    if (n == 2) return c % mod;
    if (n == 3) return d % mod;
    if (n == 4) return e % mod;
    if (n == 5) return f % mod;

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = basicIO(a, b, c, d, e, f, n-1, dp)% mod
          + basicIO(a, b, c, d, e, f, n-2, dp)% mod
          + basicIO(a, b, c, d, e, f, n-3, dp)% mod
          + basicIO(a, b, c, d, e, f, n-4, dp)% mod
          + basicIO(a, b, c, d, e, f, n-5, dp)% mod
          + basicIO(a, b, c, d, e, f, n-6, dp)% mod;

    return dp[n];
}

int main() {
    ll tc;
    cin >> tc;
    ll i=1;

    while (i <= tc) {
        ll a, b, c, d, e, f, n;
        cin >> a >> b >> c >> d >> e >> f >> n;
        vector <ll> dp(n+1, -1);

        printf("Case %d: %d\n", i, (basicIO(a, b, c, d, e, f, n, dp)+mod) % mod);
        i++;
    }
    return 0;
}

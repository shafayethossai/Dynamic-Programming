#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9, mod = 10000007;
int a, b, c, d, e, f, dp[N];

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;

    if (dp[n] != -1) {
        return dp[n];
    }
    int ans = (((((fn(n-1) + fn(n-2)) % mod + fn(n-3)) % mod + fn(n-4)) % mod + fn(n-5)) % mod + fn(n-6)) % mod;

    return dp[n] = ans;
}
int main() {
    int n, cases;
    scanf("%d", &cases);

    for (int caseno = 1; caseno <= cases; ++caseno) {
        memset (dp, -1, sizeof dp);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}

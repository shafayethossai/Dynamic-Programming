#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e6 + 7, mod = 1e9 + 7;
int n, dp[N];

int rec(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    int ans = (((((rec(n-1) % mod + rec(n-2)) % mod + rec(n-3)) % mod + rec(n-4)) % mod + rec(n-5)) % mod + rec(n-6)) % mod;

    return dp[n] = ans;
}
int main() {
    fast;
    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << rec(n) << endl;
    // vector<int> dp(n+1, 0);
 
    // dp[0] = 1;

    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=6; j++) {
    //         if (i-j >= 0) {
    //             (dp[i] += dp[i-j]) %= mod;
    //         }
    //     }
    // }
    // cout << dp[n] << endl;

    return 0;
}
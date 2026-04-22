#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9, inf = 1e9;
int n, k, h[N], dp[N];

int rec (int state) {
    if (state > n) return inf;
    if (state == n) return 0;
    if (dp[state] != -1) {
        return dp[state];
    }
    // dp[i] = abs(h[i] - h[i+1]) + rec(i+1);
    // dp[i] = min(dp[i], abs(h[i] - h[i+2]) + rec(i+2));

    int ans = abs(h[state] - h[state + 1]) + rec(state+1);

    for (int i=2; i<=k; i++) {
        ans = min(ans, abs(h[state] - h[state + i]) + rec(state+i));
    }

    return dp[state] = ans;
}

int main() {
    fast;
    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(1) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9, inf = 1e9;
int n, h[N], dp[N];

int rec (int i) {
    if (i > n) return inf;
    if (i == n) return 0;
    if (dp[i] != -1) {
        return dp[i];
    }
    dp[i] = abs(h[i] - h[i+1]) + rec(i+1);
    dp[i] = min(dp[i], abs(h[i] - h[i+2]) + rec(i+2));

    return dp[i];
}

int main() {
    fast;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
    memset(dp, -1, sizeof dp);
    cout << rec(1) << endl;

    return 0;
}
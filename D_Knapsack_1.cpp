#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll N = 109, M = 1e5 + 9;
ll n, W, weight[M], profit[M], dp[N][M];

ll cal(ll state, ll w) {
    if (state == n+1) {
        return 0;
    }
    if (dp[state][w] != -1) {
        return dp[state][w];
    }
    ll ans = cal(state+1, w);

    if (w + weight[state] <= W) {
        ans = max (ans, cal(state+1, w+ weight[state]) + profit[state]);
    }
    return dp[state][w] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> n >> W;

    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> profit[i];
    }
    memset(dp, -1, sizeof dp);
    cout << cal(1, 0) << endl;

    return 0;
}
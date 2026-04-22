#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll N = 109, inf = 1e11 + 9;
ll n, capacity, weight[N], profit[N], dp[N][N * 1000];

ll cal(ll state, ll val) {
    if (state == n+1) {
        if (val == 0) return 0;
        else return inf;
    }
    if (dp[state][val] != -1) {
        return dp[state][val];
    }
    ll ans = cal(state+1, val);
    ans = min(ans, cal(state+1, val-profit[state]) + weight[state]);

    return dp[state][val] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> n >> capacity;

    for (int i=1; i<=n; i++) {
        cin >> weight[i] >> profit[i];
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;

    for (int i=1; i<=n*1000; i++) {
        if (cal(1, i) <= capacity) {
            ans = max(ans, (ll)i);
        }
    }
    cout << ans << endl;

    return 0;
}
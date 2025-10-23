#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll N = 105;
ll n, W, w[N], Profit[N], dp[N][100005];

ll calculate(ll i, ll weight) {
    if (i == n+1) {
        return 0;
    }
    if (dp[i][weight] != -1) {
        return dp[i][weight];
    }
    ll ans = calculate(i+1, weight); // not taking

    if (weight + w[i] <= W) {
        ans = max(ans, calculate(i+1, weight+w[i]) + Profit[i]); // max of (not taking , with taking)        
    }
    return dp[i][weight] = ans;
}

int main() {
    fast;
    
    cin >> n >> W;

    for (int i=1; i<=n; i++) {
        cin >> w[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> Profit[i];
    }
    
    memset(dp, -1, sizeof dp);
    cout << calculate(1, 0) << endl;

    return 0;
}
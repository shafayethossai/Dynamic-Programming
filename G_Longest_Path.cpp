#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9;
vector<int> g[N];
int dp[N], n, m;

int rec (int node) {
    if (dp[node] != -1) return dp[node];
    int ans = 0;

    for (auto child: g[node]) {
        ans = max(ans, rec(child) + 1);
    }
    return dp[node] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> n >> m;

    for (int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;

    for (int i=1; i<=n; i++) {
        ans = max(ans, rec(i));
    }
    cout << ans << endl;

    return 0;
}
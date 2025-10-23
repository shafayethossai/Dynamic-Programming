#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll inf = LLONG_MAX;
int grid[10][10], dp[10][10];
ll n, m;

ll min_cost (ll i, ll j) {
    if (i > n || j > m) {
        return inf;
    }
    if (i == n && j == m) {
        return grid[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    return dp[i][j] = grid[i][j] + min(min_cost(i+1, j), min_cost(i, j+1));
}

void path (ll i, ll j) {
    cout << "(" << i << ", " << j << ") -> ";
    
    if (i == n && j == m) {
        return;
    }
    ll right = min_cost(i, j+1);
    ll down = min_cost(i+1, j);

    if (right <= down) {
        path(i, j+1);
    }
    else {
        path(i+1, j);
    }
}


int main() {
    fast;
    
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << min_cost(1, 1) << endl;
    cout << endl;

    path(1, 1);

    return 0;
}
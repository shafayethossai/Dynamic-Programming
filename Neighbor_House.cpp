#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 22, inf = 1e9;
int n, cost[N][4], dp[N][4];

int cal(int i, int j) {
    if (i == n && (j >= 1 && j <= 3)) {
        return cost[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = inf;

    if (j == 1) {
        ans = min(cal(i+1, 2), cal(i+1, 3)) + cost[i][j];
    }
    else if (j == 2) {
        ans = min(cal(i+1, 1), cal(i+1, 3)) + cost[i][j];
    }
    else {
        ans = min(cal(i+1, 1), cal(i+1, 2)) + cost[i][j];
    }
    return dp[i][j] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> tc;

    for (int cs=1; cs<=tc; cs++) {
        cin >> n;

        for (int i=1; i<=n; i++) {
            cin >> cost[i][1] >> cost[i][2] >> cost[i][3];
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << cs << ": " << min(cal(1, 1), min(cal(1, 2), cal(1, 3))) << endl;
    }

    return 0;
}
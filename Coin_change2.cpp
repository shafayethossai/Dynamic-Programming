#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> m >> n; // m: array size, n: total coin

    int dp[n+1], coins[m];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i=0; i<m; i++) {
        cin >> coins[i];
    }

    for (int i=0; i<=m; i++) {
        for (int j=coins[i]; j<=n; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << "Maximum Possible Ways : " << dp[n] << endl;

    return 0;
}

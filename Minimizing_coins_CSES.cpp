#include <bits/stdc++.h>
using namespace std;

int solve (vector<int> &coin, int n, vector<int> &dp) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MAX;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int mini = INT_MAX;

    for (int i=0; i<coin.size(); i++) {
        int ans = solve(coin, n - coin[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    dp[n] = mini;
    return dp[n];
}

int main () {
    int k, sum;
    cin >> k >> sum;
    vector <int> coin(k);

    for (int i=0; i<k; i++) {
        cin >> coin[i];
    }
    vector <int> dp(sum+1, -1);

    int ans = solve (coin, sum, dp);

    if (ans == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}

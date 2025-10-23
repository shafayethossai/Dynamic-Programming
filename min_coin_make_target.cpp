#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;  // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= k; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    cout << (dp[k] == INT_MAX ? -1 : dp[k]) << endl;
    return 0;
}

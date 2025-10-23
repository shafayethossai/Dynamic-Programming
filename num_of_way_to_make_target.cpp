#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(k + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make amount 0 (no coins)

    for (int coin : coins) {
        for (int i = coin; i <= k; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }

    cout << dp[k] << endl;
    return 0;
}

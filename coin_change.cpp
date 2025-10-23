//  Time Complexity: O(n * k).
//  Space Complexity: O(n + k).

#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &num, int n, vector<int> &dp) {
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

    for (int i = 0; i < num.size(); i++) {
        int ans = solveRec(num, n - num[i], dp);
        if (ans != INT_MAX) {
            mini = min(mini, 1 + ans);
        }
    }
    dp[n] = mini;

    return dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(k);

    for (int i = 0; i < k; i++) {
        cin >> num[i];
    }
    vector<int> dp(n + 1, -1);

    int ans = solveRec(num, n, dp);

    if (ans == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}

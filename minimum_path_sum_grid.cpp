#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) { // first column
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) { // first row
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < m; i++) { // remaining cells
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}

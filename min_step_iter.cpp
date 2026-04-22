#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9;
int dp[N];

int main() {
    fast;
    int n;
    cin >> n;

    dp[1] = 0;
    
    for (int i=2; i<=n; i++) {
        int ans = dp[i-1] + 1;

        if (i%2 == 0) {
            ans = min(ans, dp[i/2] + 1);
        }
        if (i%3 == 0) {
            ans = min(ans, dp[i/3] + 1);
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;

    return 0;
}
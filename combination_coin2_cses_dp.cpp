#include <bits/stdc++.h>
using namespace std;

#define    ll long long
#define    mod 1000000007

int main () {
    int n, sum;
    cin >> n >> sum;
    vector <int> coin(n);

    for (int i=0; i<n; i++) {
        cin >> coin[i];
    }
    vector <int> dp(sum+1, 0);
    dp[0] = 1;

    for (int i=0; i<n; i++) {
        for (int j=1; j<=sum; j++) {
            if (j >= coin[i]) {
                dp[j] = (dp[j] + dp[j-coin[i]]) % mod;
            }
        }
    }
    cout << dp[sum] % mod << endl;

    return 0;
}

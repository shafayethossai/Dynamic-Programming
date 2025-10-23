#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll arr[400][400];
ll dp[400][400];

ll monkey (ll i, ll j, ll k) {
    if (arr[i][j] == 0) {
        return 0;
    }
    if (i == k-1) {
        return arr[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    ll r1=0, r2=0;

    r1 = arr[i][j] + monkey(i+1, j, k);
    r2 = arr[i][j] + monkey(i+1, j+1, k);

    dp[i][j] = max(r1, r2);

    return dp[i][j];
}

int main() {
    int tc, it=1;
    cin >> tc;

    while (it <= tc) {
        memset(arr, 0, sizeof(arr));
        memset(dp, -1, sizeof(dp));
        ll n;
        cin >> n;
        ll k = 2 * n - 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> arr[i][j];
            }
        }
        ll l = 1;

        for (int i = n; i < k; i++) {
            for (int j = l; j < n; j++) {
                cin >> arr[i][j];
            }
            l++;
        }
        ll ans = monkey(0, 0, k);
        printf("Case %d: %d\n", it, ans);

        it++;
    }

    return 0;
}

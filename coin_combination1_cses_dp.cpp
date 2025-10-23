#include <bits/stdc++.h>
using namespace std;

#define    mod 1000000007
#define    ll long long

int main () {
    ll n, sum;
    cin >> n >> sum;
    vector <ll> coin(n);

    for (int i=0; i<n; i++) {
        cin >> coin[i];
    }
    vector <ll> dp(sum+1, 0);
    dp[0] = 1;

    for (int i=1; i<=sum; i++) {
        for (int j=0; j<n; j++) {
            if (i >= coin[j]) {
                dp[i] += dp[i-coin[j]] % mod;
            }
        }
    }
    cout << dp[sum] % mod << endl;


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll N = 100;
ll dp[N];

int main() {
    fast;
    int tc = 1;
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl; 

    return 0;
}
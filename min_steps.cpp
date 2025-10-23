#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9;
int dp[N];

int min_step (int n) {
    if (n == 1) {
        return 0;
    }
    if (dp[n] != -1) {
        return dp[n];
    } 
    int ans = min_step(n-1) + 1;

    if (n%2 == 0) {
        ans = min(ans, min_step(n/2) + 1);
    }
    if (n%3 == 0) {
        ans = min(ans, min_step(n/3) + 1);
    }
    dp[n] = ans;

    return dp[n];
}

int main() {
    fast;
    int tc = 1;
    //cin >> tc;
    
    while(tc--) {
        memset(dp, -1, sizeof dp);
        cout << min_step(10000) << endl;
    }
    

    return 0;
}
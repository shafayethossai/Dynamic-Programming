#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int mod = 100000007, N = 55, K = 1005;
int n, tar;
int coin[N], c[N], dp[N][K];

int rec(int state, int curr_val) {
    if (curr_val > tar) return 0;
    
    if (state == n+1) {
        if (curr_val == tar) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[state][curr_val] != -1) return dp[state][curr_val];
    int ans = 0;

    for (int i=0; i<=c[state]; i++) {
        ans += rec(state+1, curr_val + coin[state] * i);
        ans %= mod;
    }
    return dp[state][curr_val] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> tc;
    
    for (int cs=1; cs<=tc; cs++) {
        cin >> n >> tar;

        for (int i=1; i<=n; i++) {
            cin >> coin[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> c[i];
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << cs << ": " << rec(1, 0) << endl;
    }
    

    return 0;
}
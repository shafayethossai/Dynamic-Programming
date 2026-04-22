#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9, inf = 1e9;
int n, dp[N][4], arr[N][4];

int rec(int state, int cat) {
    if (state == n) {
        return arr[state][cat];
    }
    if (dp[state][cat] != -1) {
        return dp[state][cat];
    }
    int ans = -inf;

    if (cat == 1) {
        ans = max(ans, rec(state+1, 2));
        ans = max(ans, rec(state+1, 3));
    }
    else if (cat == 2) {
        ans = max(ans, rec(state+1, 1));
        ans = max(ans, rec(state+1, 3));
    }
    else {
        ans = max(ans, rec(state+1, 1));
        ans = max(ans, rec(state+1, 2));
    }
    return dp[state][cat] = arr[state][cat] + ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    memset(dp, -1, sizeof dp);
    int mx1 = rec(1, 1);
    int mx2 = rec(1, 2);
    int mx3 = rec(1, 3);
    cout << max(mx1, max(mx2, mx3)) << endl;

    return 0;
}
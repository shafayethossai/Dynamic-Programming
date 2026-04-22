#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 5005, inf = 1e8 + 7;
string s1, s2;
int dp[N][N];

int cal(int i, int j) {
    if (i == s1.size()) {
        if (j == s2.size()) return 0;
        else return s2.size() - j;
    }
    if (j == s2.size()) {
        return s1.size() - i;
    }
    if (dp[i][j] != -1) return dp[i][j];

    int ans = inf;

    if (s1[i] == s2[j]) {
        ans = min(ans, cal(i+1, j+1));
    }
    else {
        ans = min(ans, cal(i+1, j+1) + 1); // update
        ans = min(ans, cal(i, j+1) + 1); // add
        ans = min(ans, cal(i+1, j) + 1); // remove
    }
    return dp[i][j] = ans;
}

int main() {
    fast;
    int tc = 1;
    cin >> s1 >> s2;

    memset(dp, -1, sizeof dp);
    cout << cal(0, 0) << endl;

    return 0;
}
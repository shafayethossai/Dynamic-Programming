#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// int rec(int n) {
//     if (n == 0) {
//         return 0;
//     }
//     int temp = -1, m = n;

//     while (m != 0) {
//         int x = m % 10;
//         m /= 10;
//         temp = max(temp, x);
//     }
//     n -= temp;
//     return rec(n) + 1;
// }

const int inf = 1e9 + 7, N = 1e6 + 9;
int dp[N];

int rec(int n) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int temp = n;
    vector<int> digits;

    while (temp != 0) {
        digits.push_back(temp % 10);
        temp /= 10;
    }
    int ans = inf;

    for (auto it: digits) {
        if (it == 0) continue;
        ans = min(ans, rec(n - it) + 1);
    }
    return dp[n] = ans;
}

int main() {
    fast;
    int n;
    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << rec(n) << endl;

    return 0;
}
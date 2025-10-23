#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5+9, mod = 1e9+7;
int ways[N];

int count (int n) {
    if (n == 0) {
        return 1;
    }
    if (ways[n] != -1) {
        return ways[n];
    }
    int ans = 0;

    for (int i=1; i<=n; i++) {
        ans += count(n-i);
        ans %= mod;
    }
    return ways[n] = ans;
}

int main() {
    fast;
    
    memset(ways, -1, sizeof ways);
    cout << count(100) << endl;

    return 0;
}
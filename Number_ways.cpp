#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5+9, mod = 1e9+7;
int ways[N];

int count (int n) {
    if (n <= 2) {
        return 1;
    }
    if (ways[n] != -1) {
        return ways[n];
    }
    return ways[n] = (count(n-1) + count(n-3)) % mod;
}

int main() {
    fast;
    
    memset(ways, -1, sizeof ways);
    cout << count(4) << endl;

    return 0;
}
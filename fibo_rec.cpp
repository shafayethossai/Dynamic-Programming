#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

const ll N = 100;
ll dp[N];

int fibo(int i) {
    if (i <= 1) {
        return i;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    return dp[i] = fibo(i-1) + fibo(i-2);
}

int main() {
    fast;
    int tc = 1;
    int n;
    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << fibo(n) << endl;
    

    return 0;
}
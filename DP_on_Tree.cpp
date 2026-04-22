// given a rrooted tree with n nodes. find the size of all subtree in O(n)

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 9;
vector<int> g[N];
int sz[N], n;

void rec (int node, int p) {
    sz[node] = 1;

    for (auto child: g[node]) {
        if (child != p) {
            rec(child, node);
            sz[node] += sz[child];
        }
    }
}

int main() {
    fast;
    int tc = 1;
    cin >> n;

    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rec(1, 0);

    for (int i=1; i<=n; i++) {
        cout << sz[i] << " ";
    }
    cout << endl;

    return 0;
}
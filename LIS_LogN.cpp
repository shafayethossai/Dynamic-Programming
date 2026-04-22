#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 200005,  M = 200005;
int a[N], dp[N], parent[N], tree[4 * M], n;

// ---- SEGMENT TREE FUNCTIONS ----
void update(int node, int b, int e, int idx, int val) {
    if (idx < b || idx > e) return;
    if (b == e) {
        tree[node] = max(tree[node], val);
        return;
    }
    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    update(left, b, mid, idx, val);
    update(right, mid + 1, e, idx, val);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if (j < b || i > e) return 0;
    if (i <= b && e <= j) return tree[node];
    int mid = (b + e) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    int l = query(left, b, mid, i, j);
    int r = query(right, mid + 1, e, i, j);
    return max(l, r);
}

// ---- PRINT LIS SEQUENCE ----
void printLIS(int lastIndex) {
    vector<int> seq;
    while (lastIndex != -1) {
        seq.push_back(a[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(seq.begin(), seq.end());
    for (int x : seq) cout << x << " ";
    cout << endl;
}

int main() {
    fast;
    cin >> n;
    set<int> s;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    // Coordinate compression
    map<int, int> mp;
    int id = 0;
    for (auto x : s) {
        mp[x] = ++id;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }
    memset(tree, 0, sizeof(tree));
    memset(dp, 0, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    int lisLength = 0, lastIndex = -1;

    for (int i = 1; i <= n; i++) {
        int bestPrev = 0, pos = -1;
        if (a[i] > 1) bestPrev = query(1, 1, M, 1, a[i] - 1);

        dp[i] = bestPrev + 1;
        update(1, 1, M, a[i], dp[i]);

        // Find parent (previous element in LIS)
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] < a[i] && dp[j] == bestPrev) {
                parent[i] = j;
                break;
            }
        }
        if (dp[i] > lisLength) {
            lisLength = dp[i];
            lastIndex = i;
        }
    }
    cout << lisLength << endl;
    printLIS(lastIndex);

    return 0;
}

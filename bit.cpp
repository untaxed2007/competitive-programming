#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector < ll > ;
#define endl '\n'
const int N = 2e5 + 9;

ll bit[N],n;

void update(ll i,ll val) {
    for (; i <= n; i += i & -i) bit[i] += val;
}

ll query(ll i) {
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

ll query(ll l,ll r) {
    return query(r) - query(l - 1);
}

void build(vll& a) {
    for (int i = 1; i <= n; i++) {
        bit[i] += a[i];
        int j = i + (i & -i);
        if (j <= n) bit[j] += bit[i];
    }
}

void solve() {
    cin>>n;
    vll nums(n+1);
    for(ll i=1;i<=n;i++) cin>>nums[i];
    // build(nums);
    // cout<<query(1,3)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while (t--) solve();
    return 0;
}

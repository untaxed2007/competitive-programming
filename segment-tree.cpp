#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector < ll > ;
#define endl '\n'
const int N = 2e5 + 9;

void build(ll idx,ll low, ll high,vll& seg,vll& nums){
    if(low==high){
        seg[idx] = nums[low];
        return;
    }
    ll mid = low+(high-low)/2;
    build(2*idx+1,low,mid,seg,nums);
    build(2*idx+2,mid+1,high,seg,nums);
    ll parity = log2(high-low+1);
    seg[idx] = (parity%2==0 ? seg[2*idx+1]^seg[2*idx+2] : seg[2*idx+1] | seg[2*idx+2]);
}

ll query(ll idx,ll low,ll high,ll point,ll upd,vll& seg){
    if(low==high) return seg[idx]=upd;
  
    ll mid = low+(high-low)/2;
    if(point-1<=mid) query(2*idx+1,low,mid,point,upd,seg);
    else query(2*idx+2,mid+1,high,point,upd,seg);
    ll parity = log2(high-low+1);
    return seg[idx] = (parity%2==0 ? seg[2*idx+1]^seg[2*idx+2] : seg[2*idx+1] | seg[2*idx+2]);
}

void solve() {
    ll n,m; cin>>n>>m;
    ll sz = 1<<n;
    vll nums(sz),seg(4*sz);
    for(auto &a:nums) cin>>a;
    build(0,0,sz-1,seg,nums);
  
    while(m--){
        ll point,upd; cin>>point>>upd;
        cout<<query(0,0,sz-1,point,upd,seg)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long int

int n, l;
ll d[300'002];
// vector<ll> d(300'002)

int main()
{
    FASTIO;
    cin >> n >> l;
    for(int i = 1; i<n; i++){
        ll e; cin >> e;
        d[i] = (d[i-1]+e)%l;
    }
    sort(d+1, d+n);
    ll ans = 0;
    if(l%3){
        cout << 0;
        return 0;
    }
    for(int i = 0; i<n && d[i]<l/3; i++){
        ll cnt2 = upper_bound(d+1, d+n, l/3+d[i]) - lower_bound(d+1, d+n, l/3+d[i]);
        ll cnt3 = upper_bound(d+1, d+n, 2*l/3+d[i]) - lower_bound(d+1, d+n, 2*l/3+d[i]);
        ans += cnt2*cnt3;
    }
    cout << ans;
    return 0;
}
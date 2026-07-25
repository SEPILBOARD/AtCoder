#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


int main()
{
    FASTIO;
    int n, s, k;

    cin >> n >> s >> k;
    vector<int> a(n+1);
    vector<ll> psum(n+1, 0);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    ll ans = 0;
    for(int ridx = s; ridx<=n; ridx++){
        int curk = k;
        
        if(ridx-s > curk) continue;
        
        ll tans = psum[ridx]-psum[s-1];
        curk -= ridx-s;
        ans = max(ans, tans);

        if(ridx-s > curk) continue;
        curk -= ridx-s;

        int lidx = max(1, s-curk);
        tans += psum[s-1] - psum[lidx-1];

        ans = max(ans, tans);
    }

    for(int lidx = s; lidx>=1; lidx--){
        int curk = k;
        
        if(s-lidx > curk) continue;
        
        ll tans = psum[s] - psum[lidx-1];
        curk -= s-lidx;
        ans = max(ans, tans);

        if(s-lidx > curk) continue;
        curk -= s-lidx;

        int ridx = min(n, s+curk);
        tans += psum[ridx] - psum[s];

        ans = max(ans, tans);
    }

    
    cout << ans << "\n";

    return 0;
}
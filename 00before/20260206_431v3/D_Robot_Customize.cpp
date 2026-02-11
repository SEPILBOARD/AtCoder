#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
tuple<ll, ll, ll> whb[501];

bool compare(tuple<ll, ll, ll> &i, tuple<ll, ll, ll> &j)
{
    auto[wi, hi, bi] = i;
    auto[wj, hj, bj] = j;

    ll vi = 1LL*(hi+bj)-(wj);
    ll vj = 1LL*(hj+bi)-(wi);
    
    return vi>vj;
}

int main()
{
    ll ans = 0LL;
    ll bw = 0LL;
    ll hw = 0LL;

    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        ll w, h, b;
        cin >> w >> h >> b;
        whb[i] = {w, h, b};

        ans += b;
        bw += w;
    }

    sort(whb, whb+n, compare);

    for(int i = 0; i<n; i++){
        auto[w, h, b] = whb[i];
        if(hw+w > bw-w){
            break;
        }
        if(h<=b) break;
        
        ans += h;
        ans -= b;
        hw += w;
        bw -= w;
    }
    cout << ans <<"\n";
    
    return 0;
}
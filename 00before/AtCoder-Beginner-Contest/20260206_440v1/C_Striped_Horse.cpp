#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, w;
int c[200'001];

void solve()
{
    cin >> n >> w;
    vector<ll> mod(2*w+1, 0LL); 
    for(int i = 1; i<=n; i++){
        cin >> c[i];
        mod[i%(2*w)] += c[i];
    }

    ll cur = 0;
    for(int i = 0; i<w; i++){
        cur += mod[i];
    }

    ll ans = cur;
    for(int i = w; i<2*w; i++){
        cur -= mod[i-w];
        cur += mod[i];
        ans = min(ans, cur);
    }
    for(int i = 0; i<w; i++){
        cur -= mod[i+w];
        cur += mod[i];
        ans = min(ans, cur);
    }

    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();    
    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

#define MOD 998244353

ll pw(ll x, ll e)
{
    if(e == 0) return 1;

    ll half = pw(x, e/2);

    if(e%2 == 0) return (half*half)%MOD;
    else return ((half * half)%MOD * x)%MOD;
}

int main()
{
    FASTIO;
    int n;
    cin >> n;

    vector<ll> psum(n+1, 0);
    vector<ll> mux(n+1, 0);
    vector<ll> a(n+1);

    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n; i++){
        psum[i] = (psum[i-1] + pw(i, MOD-2))%MOD;
    }

    for(int i = 1; i<=(n+1)/2; i++){
        mux[i] = (mux[i-1]+(psum[n-i+1]-psum[i-1]+MOD)%MOD)%MOD;
        mux[n-i+1] = mux[i];
    }

    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans = (ans + (mux[i]*a[i])%MOD)%MOD;
    }
    cout << ans << "\n";
    
    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, k;

int main()
{
    FASTIO;
    cin >> n >> k;
    vector<ll> a(n);
    
    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i] %= k;  
    }

    sort(a.begin(), a.end());

    ll ans = 0;
    for(int i = 1; i<n; i++){
        ans = max(ans, a[i]-a[i-1]);
    }
    ans = max(ans, (k+a[0])-a[n-1]);
    cout << k-ans;

    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int cnt[200'005];
int tcnt = 0;

int main()
{
    FASTIO;
    
    cin >> n;
    for(int i = 0; i<n; i++){
        int a; cin >> a;

        if(cnt[a] == 0) tcnt++;
        cnt[a]++;
    }

    ll ans = 0;

    for(int i = 1; i<=200'000; i++){
        if(cnt[i] < 2) continue;

        ans += 1ll * cnt[i]*(cnt[i]-1)/2 * (n-cnt[i]);
    }

    cout << ans;
    
    return 0;
}
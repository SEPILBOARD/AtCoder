#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


void solve()
{
    ll h, m;
    cin >> h >> m;

    ll ad, ah, am;
    am = m%60;
    ah = h+m/60;
    ad = ah/24;
    ah = ah%24;

    cout << ad <<" " << ah << " " << am <<"\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}
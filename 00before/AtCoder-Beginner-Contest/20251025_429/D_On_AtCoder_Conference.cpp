#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int N, C;
ll m;
ll a[500'001];
vector<ll> v;
int cnt[500'001];

int vtoi(ll i)
{
    return lower_bound(v.begin(), v.end(), a[i])-v.begin();
}

int main()
{
    FASTIO;
    cin >> N >> m >> C;
    for(int i = 0; i<N; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int n = v.size();

    for(int i = 0; i<N; i++){
        cnt[vtoi(i)]++;
    }

    ll ans = 0ll;
    int eidx = 0;
    ll curCnt = 0;
    ll curM = -1;

    for(int sidx = 0; sidx<n; sidx++){
        while(curCnt < C){
            curCnt += cnt[eidx];
            eidx = (eidx+1)%n;
        }

        ll ev = v[sidx];
        ll mcnt = ev - curM;
        curM = ev;

        ans += mcnt * curCnt;
        cout << sidx <<": " << curCnt <<"\n";
        curCnt -= cnt[sidx];
    }

    ll lcnt = 0ll;
    int t = 0;
    while(lcnt < C){
        lcnt += cnt[t];
        t = (t+1)%n;
    }
    ans += (m-1-curM)*lcnt;

    cout << ans << '\n';
    return 0;
}

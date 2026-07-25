#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int N, c;
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
    cin >> N >> m >> c;
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

    int eidx = 1;
    int curCnt = 0;
    ll curM = -1;
    for(int sidx = 0; sidx<n; sidx++){
        while(curCnt < c){
            eidx %= n;
            curCnt += cnt[eidx++];
        }

        ll ev = v[sidx];
        ll mcnt = ev-curM;
        curM = ev;

        ans += mcnt*curCnt;

        curCnt -= cnt[sidx];
    }

    int sidx = 0;
    eidx = 0;
    curCnt = 0;
    while(curCnt < c){
        eidx %= n;
        curCnt += cnt[eidx++];
    }
    ans += (m-1-curM) * curCnt;

    cout << ans;
    return 0;
}
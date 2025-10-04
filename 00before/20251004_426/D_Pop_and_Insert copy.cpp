#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
char s[200'002];
int cnt0[200'002];
int cnt1[200'002];

void solve()
{
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> s[i];
    }
    
    for(int i = 1; i<=n; i++){
        cnt0[i] = cnt0[i-1];
        cnt1[i] = cnt1[i-1];

        if(s[i] == '0') cnt0[i]++;
        else cnt1[i]++;
    }


    int idx = 1;
    int l = 1, r = 1;

    int ans = 1e+9;
    while(idx<=n){
        while(idx+1<=n && s[idx+1] == s[l]) idx++;
        r = idx;
        
        if(s[l] == '0'){
            int tans = (cnt0[l-1] + cnt0[n]-cnt0[r])*2;
            tans += cnt1[l-1] + cnt1[n]-cnt1[r];
            ans = min(ans, tans);
        }
        else{
            int tans = (cnt1[l-1] + cnt1[n]-cnt1[r])*2;
            tans += cnt0[l-1] + cnt0[n]-cnt0[r];
            ans = min(ans, tans);
        }
        // cout << l <<": " <<ans <<"\n";

        idx++;
        if(idx > n) break;
        l = idx;
        r = idx;
    }

    cout << ans <<"\n";

    memset(cnt0, 0, sizeof(int)*(n+1));
    memset(cnt1, 0, sizeof(int)*(n+1));

}

int main()
{
    FASTIO;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
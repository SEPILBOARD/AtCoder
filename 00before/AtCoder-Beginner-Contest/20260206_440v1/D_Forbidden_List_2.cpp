#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, q;
map<int, int> sv;

int main()
{
    FASTIO;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for(int cq = 0; cq<q; cq++){
        int x, y;
        cin >> x >> y;

        ll lo = x-2+y;
        ll hi = 2e+9+5;
        while(lo+1<hi){
            ll mid = lo+hi>>1;
            int cnt = upper_bound(a.begin(), a.end(), mid)-lower_bound(a.begin(), a.end(), x);
            
            if(mid-x+1-cnt >= y) hi = mid;
            else lo = mid;
        }
        cout << hi << "\n";
    }
    
    return 0;
}
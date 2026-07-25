#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a1, an; 

void solve()
{
    cin >> n;
    vector<int> a;

    cin >> a1;
    for(int i = 1; i<n-1; i++){
        int e; cin >> e;
        a.push_back(e);
    }
    cin >> an;

    if(n == 2){
        if(a1*2 >= an) cout << "2\n";
        else cout << "-1\n";
        return;
    }

    sort(a.begin(), a.end());
    int bf = a1;
    int ans = 2;
    while(2*bf < an){
        auto iter = upper_bound(a.begin(), a.end(), 2*bf)-1;
        if(iter == a.end() || a[iter-a.begin()] == bf){
            cout << "-1\n";
            return;
        }
        bf = a[iter-a.begin()];
        ans++;
    }
    cout << ans <<"\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}
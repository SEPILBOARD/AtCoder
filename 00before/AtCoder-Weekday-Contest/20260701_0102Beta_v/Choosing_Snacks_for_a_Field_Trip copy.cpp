#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int s[1'000'001];

int main()
{
    FASTIO;

    multiset<int> rset;
    cin >> n >> m;

    for(int i = 0 ; i<n; i++){
        int r;
        cin >> r;
        rset.insert(r);
    }

    int ans = 0;
    for(int i = 0; i<m; i++){
        cin >> s[i];

        auto it = rset.upper_bound(s[i]);
        if(it == rset.begin()) continue;

        it--;
        ans++;
        rset.erase(it);
    }
    
    cout << ans <<"\n";

    return 0;
}
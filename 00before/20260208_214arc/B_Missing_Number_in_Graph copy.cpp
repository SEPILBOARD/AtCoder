#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
bool v[200'005];
bool chk[200'005];

void solve()
{
    cin >> n >> m;

    memset(v, false, sizeof(bool)*(n+1));
    memset(chk, false, sizeof(bool)*(n+1));
    vector<vector<pair<int, int>> > adj(n+1, vector<pair<int, int>>());
    for(int i = 0; i<m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    if(n == 1){
        cout << "-1\n";
        return;
    }

    if(n == 2){
        int xr = adj[1][0].second;
        if(xr == 1) cout << "2\n";
        if(xr == 2) cout << "1\n";
        if(xr == 3) cout << "0\n";
        return;
    }

    int a = 1;
    auto[b, axb] = adj[a][0];
    auto[c, bxc] = adj[b][0];
    int cxa = axb^bxc;

    // cout << bxc <<"\n";

    queue<pair<int, int>> q;
    q.push({a, bxc});
    v[1] = true;
    while(!q.empty()){
        auto[cur, val] = q.front();
        q.pop();

        // cout << cur <<"\n";

        chk[val] = true;

        for(auto[nxt, nxr]: adj[cur]){
            if(v[nxt]) continue;
            q.push({nxt, val^nxr});
            v[nxt] = true;
        }
    }

    for(int i = 0; i<=n; i++){
        if(!chk[i]){
            cout << i <<"\n";
            return;
        }
    }
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}
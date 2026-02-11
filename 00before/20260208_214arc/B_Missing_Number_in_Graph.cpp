#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
bool v[200'005];

void solve()
{
    cin >> n >> m;

    memset(v, false, sizeof(bool)*(n+1));
    vector<vector<pair<int, int>> > adj(n+1, vector<pair<int, int>>());
    for(int i = 0; i<m; i++){
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
        adj[b].push_back({a, x});
    }

    if(n%2){
        cout << "-1\n";
        return;
    }

    queue<pair<int, int>> q;
    v[1] = true;
    q.push({1, 0});

    int tot = 0;

    while(!q.empty()){
        auto[cur, c] = q.front();
        q.pop();

        tot ^= c;

        for(auto[nxt, X]: adj[cur]){
            if(v[nxt]) continue;
            v[nxt] = true;
            q.push({nxt, c^X});
        }
    }

    for(int i = 0; i<=n; i++){
        tot ^= i;
    }
    cout << tot <<"\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}
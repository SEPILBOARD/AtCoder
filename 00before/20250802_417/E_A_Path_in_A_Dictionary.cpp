#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m, x, y;
vector<int> adj[1001];
bool v[1001];
stack<int> st;

bool dfs(int cur)
{   
    v[cur] = true;
    if(cur == y){
        st.push(cur);
        return true;
    }

    for(int e: adj[cur]){
        if(v[e]) continue;

        if(dfs(e)){
            st.push(cur);
            return true;
        }
    }

    // v[cur] = false;
    return false;
}

void solve()
{
    cin >> n >> m >> x >> y;
    for(int i = 1; i<=n; i++){
        adj[i].clear();
        v[i] = false;
    }

    for(int i = 0; i<m; i++){
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    for(int i = 1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(x);
    while(!st.empty()){
        cout << st.top() <<" ";
        st.pop();
    }
    cout << "\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve();    
    return 0;
}
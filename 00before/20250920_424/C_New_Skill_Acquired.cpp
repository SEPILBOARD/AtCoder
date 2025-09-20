#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
vector<int> adj[200'001];
vector<int> start;

int ans = 0;
bool v[200'001];

void dfs(int cur)
{
    v[cur] = true;
    ans++;
    for(int e: adj[cur]){
        if(v[e]) continue;

        v[e] = true;
        dfs(e);
    }
}

int main()
{
    FASTIO;

    cin >> n;
    for(int i = 1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        if(a==0){
            start.push_back(i);
        }
        else{
            adj[a].push_back(i);
            adj[b].push_back(i);
        }
    }

    for(int s: start){
        if(v[s]) continue;
        dfs(s);
    }

    cout << ans;

    return 0;
}
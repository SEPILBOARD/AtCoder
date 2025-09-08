#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
int dgr[10];
bool adj[10][10];

bool v[10];
int tans = 987654321;

void bt(int cnt, int start ,int cur, int ans)
{
    // cout << cur << " ";
    if(cnt == n){
        int p = dgr[cur];
        if(!adj[cur][start]) p+=2;
        if(adj[cur][start]) p--;
        // else p++;
        tans = min(tans, ans+p);
        // cout << "\n";
    }

    else{
        for(int i = 1; i<=n; i++){
            if(v[i]) continue;
            v[i] = true;
            int p = dgr[cur];
            if(adj[cur][i]){              
                bt(cnt+1, start, i, ans+p-2);    
            }
            else{
                bt(cnt+1, start, i, ans+p+2);
            }
            v[i] = false;
        }
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int s, e;
        cin >> s >> e;
        dgr[s]++;
        dgr[e]++;
        adj[s][e] = true;
        adj[e][s] = true;
    }

    for(int i = 1; i<=n; i++){
        v[i] = true;
        bt(1, i, i, 0);
        v[i] = false;
    }
    cout << tans;
    return 0;
}
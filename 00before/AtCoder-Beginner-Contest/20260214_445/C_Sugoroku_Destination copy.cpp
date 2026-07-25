#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int CIDX = 0;

int n;
int a[500'005];
vector<tuple<int, int, int, vector<int>>> cyc;

bool v[500'005];
int wcyc[500'005];
int prvM[500'005];

int dfs(int idx, int cur, int mod)
{
    // v[cur] = true;
    // cout << cur <<": " << wcyc[cur] <<"\n";
    if(wcyc[cur] != -1){
        if(wcyc[cur] == idx){
            cyc.push_back({idx, 0, mod-prvM[cur], {cur}});
            return idx;
        }
        else{
            cyc.push_back({wcyc[cur], mod, mod, {cur}});
            return wcyc[cur];
        }
    }

    wcyc[cur] = idx;
    prvM[cur] = mod;

    int cycIdx = dfs(idx, a[cur], mod+1);
    if(cycIdx != idx || mod){
        auto& [cycIdx, add, size, vec] = cyc[idx];
        vec.push_back(mod);
    }
    return cycIdx;
}

int main()
{
    FASTIO;
    cin >> n;
    cyc.resize(n+1);
    memset(wcyc, -1, sizeof wcyc);
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = 1; i<=n; i++){
        if(wcyc[i] == -1){
            dfs(CIDX, i, 0);
            CIDX++;
        }

        // cout << "ok\n"; return 0;
    }

    for(int i = 1; i<=n; i++){
        cout << wcyc[i] <<" ";
    }


    return 0;
}
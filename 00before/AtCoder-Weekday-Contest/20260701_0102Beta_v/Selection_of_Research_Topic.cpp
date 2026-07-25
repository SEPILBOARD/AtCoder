#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int m;
vector<int> need[16];
pair<int, int> pc[16];

int main()
{
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int p, c;
        cin >> p >> c;
        pc[i] = {p, c};
    }

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        need[u-1].push_back(v-1);
    }

    ll ans = 0;
    for(int bit = 0; bit<(1<<15); bit++){
        vector<int> idx;
        for(int shift = 0; shift<15; shift++){
            if(bit&(1<<shift)){
                idx.push_back(shift);
            }
        }

        bool imposs = false;
        for(int i = 0; i<idx.size(); i++){
            for(int nd: need[idx[i]]){
                auto it = lower_bound(idx.begin(), idx.end(), nd);
                if(it != idx.end() && *it == nd){
                    continue;
                }

                imposs = true;
                break;
            }
            if(imposs) break;
        }

        if(imposs) continue;

        ll tans = 0;
        for(int i = 0; i<idx.size(); i++){
            auto[p, c] = pc[idx[i]];
            tans += p-c;
        }
        ans = max(ans, tans);
    }

    cout << ans << "\n";
    
    return 0;
}
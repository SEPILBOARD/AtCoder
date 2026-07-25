#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int dp[10][1<<8];
char a[10][10];
set<int> psb[10];

void solve()
{
    memset(dp, 0x7f, sizeof(dp));

    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    psb[0].insert((1<<m)-1);
    dp[0][(1<<m)-1] = 0;

    for(int i = 1; i<=n; i++){
        for(int prev: psb[i-1]){
            for(int state = 0; state<(1<<m); state++){
                bool flag = true;
                if(a[i][0] == '.' && (state&1) == 0) continue;
                for(int j = 1; j<m; j++){
                    if(a[i][j] == '.' && (state&(1<<j)) == 0){
                        flag = false;
                        break;
                    }
                    if((prev&(1<<j-1)) == 0 && (prev&(1<<j)) == 0 && (state&(1<<j-1)) == 0 && (state&(1<<j)) == 0){
                        flag = false;
                        break;
                    }
                }
                if(!flag) continue;

                psb[i].insert(state);
                int cnt = 0;
                for(int j = 0; j<m; j++){
                    if(a[i][j] == '#'){
                        if(state&(1<<j)){
                            cnt++;
                        }
                    }
                }
                
                dp[i][state] = min(dp[i][state], dp[i-1][prev] + cnt);
            }
        }
    }

    int ans = 987654321;
    for(int state = 0; state<(1<<m); state++){
        ans = min(ans, dp[n][state]);
    }
    cout << ans <<"\n";

    // for(int i = 0; i<=n; i++){
    //     for(int s: psb[i]){
    //         cout << i <<": " << bitset<5>(s) <<", " << dp[i][s] <<"\n";
    //     }
    // }

    for(int i = 0; i<=n; i++){
        psb[i].clear();
    }
}

int main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}
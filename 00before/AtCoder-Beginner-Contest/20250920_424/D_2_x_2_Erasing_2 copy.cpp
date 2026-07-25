#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
char a[10][10];

void solve()
{
    int ans = 0;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(a[i-1][j-1] == '#' && a[i-1][j] == '#' && a[i][j-1] == '#' && a[i][j] == '#'){
                if(j>m/2) a[i][j-1] = '.';
                else a[i][j] = '.';
                ans++;
            }
        }
    }
    cout << ans << "\n";

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout << a[i][j];
    //     }
    //     cout << "\n";
    // }
}

int main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}
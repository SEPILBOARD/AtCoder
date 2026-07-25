#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
char a[1'001][1'001];

bool v[1'001][1'001];

int ans = 0;

void dfs(int x, int y)
{
    v[x][y] = true;

    for(int t = 0; t<4; t++){
        int nx = x+dx[t];
        int ny = y+dy[t];

        if(nx<0 || ny<0 || n<=nx || m<=ny) continue;
        if(a[nx][ny] == '#') continue;
        if(v[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        if(!v[i][0] && a[i][0]=='.'){
            dfs(i, 0);
        }
        if(!v[i][m-1] && a[i][m-1]=='.'){
            dfs(i, m-1);
        }
    }

    for(int i = 0; i<m; i++){
        if(!v[0][i] && a[0][i]=='.'){
            dfs(0, i);
        }
        if(!v[n-1][i] && a[n-1][i]=='.'){
            dfs(n-1, i);
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] || a[i][j] == '#') continue;

            dfs(i, j);
            ans++;
            // cout << i << ", " << j <<"\n";
        }
    }

    cout << ans << "\n";

    return 0;
}
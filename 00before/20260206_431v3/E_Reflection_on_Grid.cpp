#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;

void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(n+1, vector<char>());
    vector<vector<vector<int> > > v(n, vector<vector<int> >());
    for(int i = 0; i<n; i++){
        a[i].resize(m+1);
        v[i].resize(m+1, vector<int>(4, 0));
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> a[i][j];
        }
    }

    deque<tuple<int, int, int, int>> dq;
    dq.push_back({0, 0, 0, 0});
    while(!dq.empty()){
        auto[x, y, t, d] = dq.front();
        dq.pop_front();

        if(x == n-1 && y==m){
            cout << d << "\n";
            return;
        }

        for(int k = 0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx<0 || ny<0) continue;
            if(nx==n-1 && ny==m && k==0){
                if(v[nx][ny][k]) continue;
                
                if(k == 0){
                    if(t == 0 && a[x][y] == 'A'){
                        dq.push_front({nx, ny, k, d});
                        v[nx][ny][k] = true; 
                    }
                    else if(t==2 && a[x][y] == 'B'){
                        dq.push_front({nx, ny, k, d});
                        v[nx][ny][k] = true;
                    }
                    else if(t==3 && a[x][y] == 'C'){
                        dq.push_front({nx, ny, k, d});
                        v[nx][ny][k] = true;
                    }
                    else{
                        dq.push_back({nx, ny, k, d+1});
                        v[nx][ny][k] = true;
                    }
                }
            }
            else if(nx>=n || ny>=m) continue;
            if(v[nx][ny][k]) continue;

            if(k == 0){
                if(t == 0 && a[x][y] == 'A'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true; 
                }
                else if(t==2 && a[x][y] == 'B'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else if(t==3 && a[x][y] == 'C'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else{
                    dq.push_back({nx, ny, k, d+1});
                    v[nx][ny][k] = true;
                }
            }
            else if(k == 1){
                if(t == 1 && a[x][y] == 'A'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true; 
                }
                else if(t==2 && a[x][y] == 'C'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else if(t==3 && a[x][y] == 'B'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else{
                    dq.push_back({nx, ny, k, d+1});
                    v[nx][ny][k] = true;
                }
            }
            else if(k == 2){
                if(t == 2 && a[x][y] == 'A'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true; 
                }
                else if(t==1 && a[x][y] == 'C'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else if(t==0 && a[x][y] == 'B'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else{
                    dq.push_back({nx, ny, k, d+1});
                    v[nx][ny][k] = true;
                }
            }
            else if(k == 3){
                if(t == 3 && a[x][y] == 'A'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true; 
                }
                else if(t==1 && a[x][y] == 'B'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else if(t==0 && a[x][y] == 'C'){
                    dq.push_front({nx, ny, k, d});
                    v[nx][ny][k] = true;
                }
                else{
                    dq.push_back({nx, ny, k, d+1});
                    v[nx][ny][k] = true;
                }
            }
        }
    }

    
}

int main()
{
    FASTIO;
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}
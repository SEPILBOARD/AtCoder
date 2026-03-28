#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int adj[101][101];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            cin >> adj[i][j];
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            for(int k = j+1; k<=n; k++){
                if(adj[i][j]+adj[j][k]<adj[i][k]){
                    // cout << i <<", " << j << ", " << k <<"\n";
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
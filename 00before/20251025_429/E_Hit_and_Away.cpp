#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
vector<int> adj[200'001];

bool v[200'001];
string s;
int dist[200'001];

int main()
{
    FASTIO;

    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int U, V;
        cin >> U >> V;
        adj[U-1].push_back(V-1);
        adj[V-1].push_back(U-1);
    }
    cin >> s;

    queue<pair<int, int>> q;

    for(int i = 0; i<n; i++){
        if(s[i] == 'S'){
            q.push({i, 0});
            v[i] = true;
        }
    }

    while(!q.empty()){
        auto[cur, d] = q.front();
        dist[cur] = d;
        q.pop();

        for(int e: adj[cur]){
            if(v[e]){
                if(s[e] == 'D'){
                    dist[cur] = dist[e]+d+1;
                }
                else{
                    
                }

                continue;
            }

            v[e] = true;
            q.push({e, d+1});
        }
    }
    
    return 0;
}
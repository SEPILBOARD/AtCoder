#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int x, n, q;
bool v[1000];
int w[1000];

int main()
{
    FASTIO;
    cin >> x >> n;
    for(int i = 1; i<=n; i++) cin >> w[i];

    cin >> q;
    for(int i = 0; i<q; i++){
        int t; cin >> t;
        if(v[t]){
            v[t] = false;
            x -= w[t];
            cout << x <<"\n";
        }
        else{
            v[t] = true;
            x += w[t];
            cout << x << "\n";
        }
    }
    
    return 0;
}
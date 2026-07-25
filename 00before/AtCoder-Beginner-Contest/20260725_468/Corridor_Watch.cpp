#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int M, D;
    cin >> M >> D;

    vector<char> a(M);
    for(int i = 0; i<M; i++){
        cin >> a[i];
    }

    vector<char> gam(M, false);
    for(int i = 0; i<M; i++){
        if(a[i] == '.') continue;

        int dist = 0;
        for(int j = i; j>=0; j--){
            if(dist>D) break;
            gam[j] = true;
            dist++;
        }
        dist = 0;
        for(int j = i; j<M; j++){
            if(dist>D) break;
            gam[j] = true;
            dist++;
        }
    }

    int ans = 0;
    for(int i = 0; i<M; i++){
        if(gam[i]) continue;

        ans++;
    }

    cout << ans << "\n";
    
    return 0;
}
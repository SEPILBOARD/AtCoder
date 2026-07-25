#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int N;
vector<int> P;
vector<int> Q;

int ans = 0;
int chk[11];
vector<int> cur;

void bt()
{
    if(cur.size() == N){
        if(P<cur && cur<Q){
            // for(int e: cur){
            //     cout  << e << " ";
            // }
            // cout <<  "\n";
            ans++;
        }
        return;
    }

    for(int i = 1; i<=N; i++){
        if(chk[i]) continue;
        chk[i] = true;
        cur.push_back(i);
        bt();

        chk[i] = false;
        cur.pop_back();
    }
}

int main()
{
    FASTIO;

    cin >> N;
    P.resize(N);
    Q.resize(N);

    for(int i = 0; i<N; i++){
        cin >> P[i];
    }
    for(int i = 0; i<N; i++){
        cin >> Q[i];
    }

    bt();
    cout << ans << "\n";
    
    return 0;
}
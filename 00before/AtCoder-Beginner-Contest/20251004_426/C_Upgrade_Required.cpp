#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, q;
int cnt[1'000'001];

int main()
{
    FASTIO;
    cin >> n >> q;

    queue<int> qu;
    for(int i = 1; i<=n; i++){
        qu.push(i);
        cnt[i] = 1;
    }

    int x, y;
    for(int i = 0; i<q; i++){
        cin >> x >> y;
        
        int cur = 0;
        while(qu.front() <= x){
            int f = qu.front();
            qu.pop();
            cur+=cnt[f];
        }
        cout << cur <<"\n";
        cnt[y] += cur;
    }

    

    return 0;
}
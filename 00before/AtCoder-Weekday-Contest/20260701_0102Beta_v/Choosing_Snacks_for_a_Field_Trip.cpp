#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;


int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<int> r(n);
    for(int i = 0; i<n; i++){
        cin >> r[i];
    }

    int mns = INT_MAX;
    for(int i = 0; i<m; i++){
        int s;
        cin >> s;
        mns = min(mns, s);
    }

    int ans = 0;
    for(int i = 0; i<n; i++){
        if(r[i] <= mns){
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
int a[500'005];
int ans[500'005];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }

    for(int i = n; i>=1; i--){
        if(a[i] == i) ans[i] = i;
        else ans[i] = ans[a[i]];
    }

    for(int i = 1; i<=n; i++){
        if(i > 1) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}
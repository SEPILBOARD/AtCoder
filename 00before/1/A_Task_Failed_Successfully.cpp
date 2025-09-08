#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, ans;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a<b) ans++;
    }

    cout << ans;
    return 0;
}
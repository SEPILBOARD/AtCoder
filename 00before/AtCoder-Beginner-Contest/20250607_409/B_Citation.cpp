#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
int a[101];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i<=n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(i<=a[j]) cnt++;
        }
        if(cnt>=i) ans = max(ans, i);
    }
    cout << ans;
    return 0;
}
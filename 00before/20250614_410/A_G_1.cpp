#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, k;
int a[101];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++) cin >> a[i];
    cin >> k;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(k<=a[i]) ans++;
    }
    cout << ans;
    return 0;
}
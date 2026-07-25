#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
map<int, int> ai;

int main()
{
    FASTIO;
    cin >> n;
    long long int ans = 0;
    for(int i = 1; i<=n; i++){
        int a; cin >> a;
        ans += ai[i-a];
        ai[i+a]++;
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;

int main()
{
    FASTIO;
    cin >> n >> m;

    for(int i = 1; i<=n; i++){
        if(i<=m) cout << "OK\n";
        else cout << "Too Many Requests\n";
    }
    return 0;
}
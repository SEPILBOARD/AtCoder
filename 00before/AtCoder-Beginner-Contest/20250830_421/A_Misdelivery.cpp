#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

map<int, string> m;

int main()
{
    FASTIO;
    int n; cin >> n;
    for(int i = 1; i<=n; i++){
        string s; cin >> s;
        m[i] = s;
    }
    int x; string y;
    cin >> x >> y;
    if(m[x] == y) cout << "Yes";
    else cout << "No";
    return 0;
}
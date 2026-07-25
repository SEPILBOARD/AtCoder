#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, m;
multiset<int> s;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int e; cin >> e;
        s.insert(e);
    }
    for(int i = 0; i<m; i++){
        int b; cin >> b;
        auto it = s.lower_bound(b);
        if(it == s.end()) continue;
        if(*it != b) continue;
        
        s.erase(it);
    }

    for(int e: s) cout << e <<" ";

    return 0;
}
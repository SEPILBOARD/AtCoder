#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m, k;
vector<int> c[11];

int main()
{
    FASTIO;
    cin >> n >> m >> k;

    for(int q = 0; q<k; q++){
        int a, b;
        cin >> a >> b;
        c[a].push_back(b);
        if(c[a].size()==m) cout << a <<" ";
    }

    
    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int a[200'001];

map<int, int> mod;

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> a[i];

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(a[i]%m == 0) cnt++;
    }
    cout << cnt;
    
    

    return 0;
}
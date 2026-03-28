#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int a[101];
int b[101];

int main()
{
    FASTIO;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int ta, tb;
        cin >> ta >> tb;
        a[ta]++;
        b[tb]++;
    }

    for(int i = 1; i<=m; i++){
        cout << b[i]-a[i] <<"\n";
    }
    
    return 0;
}
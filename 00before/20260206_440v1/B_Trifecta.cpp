#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
pair<int, int> a[2000];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    cout << a[0].second <<" " << a[1].second <<" " << a[2].second;
    
    
    return 0;
}
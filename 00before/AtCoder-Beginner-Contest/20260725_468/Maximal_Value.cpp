#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 1; i<n-1; i++){
        if(a[i-1]<a[i] && a[i]>a[i+1]){
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string s;

void solve()
{
    cin >> n;
    cin >> s;
    
    if(n==1){
        cout << s <<"\n";
        return;
    }

    int idx = 0;
    int sidx = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i]<=s[i+1]) continue;
        idx = i;
        for(int j = idx+1; s[i]>=s[j] && j<n; j++){
            sidx = j+1;
        }
        break;
    }
    if(idx == sidx){
        cout << s <<"\n";
        return;
    }
    // cout << idx << ", " <<sidx <<"\n";

    for(int i = 0; i<sidx; i++){
        if(i == idx) continue;
        cout << s[i];
    }
    cout << s[idx];
    for(int i = sidx; i<n; i++) cout << s[i];
    cout << "\n";
}

int main()
{
    FASTIO;
    int tc; cin >> tc;
    while(tc--) solve(); 
    return 0;
}
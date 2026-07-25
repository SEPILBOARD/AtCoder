#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
string s[101];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> s[i];
        m = max(m, (int)s[i].length());
    }

    for(int i = 0; i<n; i++){
        int cnt = (m-s[i].length())/2;
        for(int j = 0; j<cnt; j++) cout <<".";
        cout << s[i];
        for(int j = 0; j<cnt; j++) cout <<".";
        cout << "\n";
    }
    
    return 0;
}
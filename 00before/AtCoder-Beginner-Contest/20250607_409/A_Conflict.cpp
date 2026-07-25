#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string t, a;

int main()
{
    FASTIO;
    cin >> n;
    cin >> t;
    cin >> a;
    for(int i = 0; i<n; i++){
        if(a[i] == 'o' && t[i] == 'o'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}
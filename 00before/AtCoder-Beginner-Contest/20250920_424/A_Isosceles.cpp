#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int a, b, c;
    cin >> a >> b >> c;

    if(a==b || b==c || a==c) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
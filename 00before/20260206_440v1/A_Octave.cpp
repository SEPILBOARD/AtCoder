#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

ll x, y;

int main()
{
    FASTIO;
    cin >> x >> y;
    cout << x*pow(2, y);
    return 0;
}
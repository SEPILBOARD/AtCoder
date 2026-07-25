#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int h, b;

int main()
{
    FASTIO;
    cin >> h >> b;
    if(h>b) cout << h-b;
    else cout << 0;
    return 0;
}
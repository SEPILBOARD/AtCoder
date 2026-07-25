#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, a, b;
string s;

int main()
{
    FASTIO;
    cin >> n >> a >> b;
    cin >> s;
    for(int i = a; i<n-b; i++) cout << s[i];
    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;

int main()
{
    FASTIO;
    cin >> s;
    if(s[0] == s.back()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
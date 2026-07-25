#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;

int main()
{
    FASTIO;
    cin >> s;
    if(s.length()!=5 && s.length() != 10) cout << "No";
    else cout << "Yes";
    return 0;
}
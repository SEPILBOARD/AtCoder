#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string x;
string y;
// o s l

int main()
{
    FASTIO;
    cin >> x;
    cin >> y;

    if(x[0] == 'O'){
        if(y[0] == 'O') cout << "Yes\n";
        else cout << "No\n";
    }
    else if(x[0] == 'S'){
        if(y[0] == 'L') cout << "No\n";
        else cout << "Yes\n";
    }
    else{
        cout << "Yes\n";
    }

    return 0;
}
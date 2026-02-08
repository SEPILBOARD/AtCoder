#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int x, y, z;

int main()
{
    FASTIO;
    cin >> x >> y >> z;
    if((x-y*z)>=0 && (x-y*z)%(z-1) == 0){
        cout << "Yes\n";
        return 0;
    }
    else cout << "No\n";

    

    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;

int main()
{
    FASTIO;
    cin >> n;
    for(int i = n; i>=2; i--){
        cout << i <<",";
    }
    cout << "1";
    return 0;
}
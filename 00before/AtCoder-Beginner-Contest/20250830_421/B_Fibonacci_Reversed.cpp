#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

long long int a[11];

long long int rev(int x)
{
    vector<int> t;
    while(x){
        t.push_back(x%10);
        x/=10;
    }
    long long int ret = 0;
    for(int e: t){
        ret += e;
        ret *=10;
    }
    return ret/10;
}

int main()
{
    FASTIO;
    cin >> a[1] >> a[2];

    for(int i = 3; i<=10; i++){
        a[i] = rev(a[i-1]+a[i-2]);
    }
    cout << a[10];
    return 0;
}
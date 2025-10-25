#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m;
int sum = 0;
int a[101];

int main()
{
    FASTIO;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 0; i<n; i++){
        if(sum-a[i] == m){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
    

    return 0;
}
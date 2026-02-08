#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;

int main()
{
    FASTIO;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin >> a[i];
    
    for(int i = 0; i<n; i++){
        bool flag = false;
        for(int j = i-1; j>=0; j--){
            if(a[j] > a[i]){
                cout << j+1 <<"\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout << "-1\n";
    }
    
    return 0;
}
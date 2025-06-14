#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, q;
int a[1'000'001];

int main()
{
    FASTIO;
    cin >> n >> q;
    for(int i = 0; i<n; i++) a[i] = i+1;

    int sidx = 0;
    while(q--){
        int qur;
        cin >> qur;
        if(qur == 1){
            int p, x;
            cin >> p >> x;
            a[(sidx+p-1)%n] = x;
        }
        else if(qur == 2){
            int p;
            cin >> p;
            cout << a[(sidx+p-1)%n] <<"\n";
        }
        else{
            int k;
            cin >> k;
            sidx = (sidx+k)%n;
        }
    }
    return 0;
}
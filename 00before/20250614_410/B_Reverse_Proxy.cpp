#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, q;
int x[101];
int b[101];

int main()
{
    FASTIO;
    cin >> n >> q;
    for(int i = 0; i<q; i++){
        int e; cin >> e;
        if(e!=0){
            cout << e <<" "; 
            b[e]++;
            continue;
        }
        
        int cnt = 9876;
        int num = 0;
        for(int i = 1; i<=n; i++){
            if(b[i]<cnt){
                cnt = b[i];
                num = i;
            }
        }
        b[num]++;
        cout << num <<" ";
    }


    return 0;
}
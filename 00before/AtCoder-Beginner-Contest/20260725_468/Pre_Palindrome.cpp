#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;



int main()
{
    FASTIO;
    int n;
    string s;
    cin >> s;
    n = s.length();

    ll ans = 0;
    for(int i = 0; i<n-1; i++){
        int lidx = i;
        int ridx = i;

        int flag = false;
        while(0<=lidx && ridx<n){
            if(s[lidx] != s[ridx]){
                if(flag){
                    break;
                }
                flag = true;
            }
            ans++;
            lidx--;
            ridx++;
        }

        lidx = i;
        ridx = i+1;
        flag = false;
        while(0<=lidx && ridx<n){
            if(s[lidx] != s[ridx]){
                if(flag){
                    break;
                }
                flag = true;
            }
            ans++;
            lidx--;
            ridx++;
        }
    }

    cout << ans+1 << "\n";
    
    return 0;
}
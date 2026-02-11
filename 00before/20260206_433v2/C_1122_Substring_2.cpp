#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
string s;

int main()
{
    FASTIO;
    int ans = 0;

    cin >> s;
    n = s.length();

    bool nxt = false;
    int prv = -1;
    int scnt = 0;
    int bcnt = 0;
    for(int i = 0; i<n; i++){
        int cur = s[i]-'0';
        
        if(nxt){
            if(prv == cur){
                bcnt++;
            }
            else if(prv+1 == cur){
                ans += min(bcnt, scnt);
                prv = cur;
                scnt = bcnt;
                bcnt = 1;
                continue;
            }
            else{
                // cout << i <<": " << min(bcnt, scnt) <<"\n";
                ans += min(bcnt, scnt);
                prv = cur;
                scnt = 1;
                bcnt = 0;
                nxt = false;
                continue;
            }

            if(bcnt >= scnt){
                // cout << i <<": " << min(bcnt, scnt) <<"\n";
                ans += min(bcnt, scnt);
                scnt = bcnt;
                bcnt = 0;
                nxt = false;
            }
        }
        else{
            if(prv+1 == cur){
                prv = cur;
                bcnt++;
                nxt = true;
            }
            else if(prv == cur){
                scnt++;
            }
            else{
                prv = cur;
                scnt = 1;
            }
        }

        // if(i == 9){
        //     cout << "--\n";
        //     cout << prv << ", " << scnt <<", " << bcnt <<"\n";
        // }
    }
    ans += min(scnt, bcnt);

    cout << ans;

    return 0;
}
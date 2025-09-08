#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

long long int xa, ya, xb, yb;
long long int n, m, l;
queue<pair<char, int>> qa;
queue<pair<char, int>> qb;

bool check()
{
    long long int dx = abs(xa-xb);
    long long int dy = abs(ya-yb);

    if(dx == dy && qa.front().second >= dx && qb.front().second >= dy) return true;
    else return false;
}

int main()
{
    FASTIO;
    cin >> xa >> ya >> xb >> yb;
    cin >> n >> m >> l;
    for(int i = 0 ; i<m; i++){
        char c; int rep;
        cin >> c >> rep;
        qa.push({c, rep});
    }
    for(int i = 0 ; i<l; i++){
        char c; int rep;
        cin >> c >> rep;
        qb.push({c, rep});
    }

    long long int ans = 0;
    bool fs = false;
    if(xa == xb && ya == yb) fs = true;
    while(!qa.empty()){    
        auto [ca, ra] = qa.front();
        auto [cb, rb] = qb.front();
        int mr = min(ra, rb);
        bool flag = check();
        if(flag){
            if(ya < yb){
                if(xa<xb){
                    if(ca == 'U' && cb == 'L') ans++;
                    if(ca == 'R' && cb == 'D') ans++;
                }
                else if(xa>xb){
                    if(ca == 'D' && cb == 'L') ans++;
                    if(ca == 'R' && cb == 'U') ans++;
                }
            }
            else if(ya > yb){
                if(xa<xb){
                    if(ca == 'U' && cb == 'R') ans++;
                    if(ca == 'L' && cb == 'D') ans++;
                }
                else if(xa>xb){
                    if(ca == 'D' && cb == 'R') ans++;
                    if(ca == 'L' && cb == 'U') ans++;
                }
            }
        }
        if(ya == yb){
            if(xa>xb){
                if(ca == 'D' && cb == 'U' && (ya-yb)%2 == 0 && 2*mr>=ya-yb) ans++;
            }
            else if(xa<xb){
                if(ca == 'U' && cb == 'D' && (yb-ya)%2 == 0 && 2*mr>=yb-ya) ans++;
            }
            else{
                ans += min(ra, rb);
            }
        }
        else if(xa == xb){
            if(ya>yb){
                if(ca == 'L' && cb == 'R' && (xa-xb)%2 == 0 && 2*mr>=xa-xb) ans++;
            }
            else if(ya<yb){
                if(ca == 'R' && cb == 'L' && (xb-xa)%2 == 0 && 2*mr>=xb-xa) ans++;
            }
        }
        
        if(ca == 'R') ya += mr;
        if(ca == 'L') ya -= mr;
        if(ca == 'U') xa += mr;
        if(ca == 'D') xa -= mr;

        if(cb == 'R') yb += mr;
        if(cb == 'L') yb -= mr;
        if(cb == 'U') xb += mr;
        if(cb == 'D') xb -= mr;

        qa.front().second -= mr;
        qb.front().second -= mr;
        if(qa.front().second == 0) qa.pop();
        if(qb.front().second == 0) qb.pop();
    }

    if(fs) ans = max(0ll, ans-1);
    cout << ans;
    return 0;
}
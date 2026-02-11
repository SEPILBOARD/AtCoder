#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n;
char a[101][101];

int main()
{
    FASTIO;
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    bool flag = true;
    for(int s = 2; s<=2*n; s++){
        int cur = 10;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i+j != s) continue;

                if(a[i][j] != '?'){
                    if(cur != 10 && cur != a[i][j]-'0'){
                        flag = false;
                        break;
                    }
                    cur = a[i][j]-'0';
                }
            }
            if(!flag) break;
        }
        if(!flag) break;

        if(cur == 10) cur = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(i+j != s) continue;

                a[i][j] = '0'+cur;
            }
        }
    }

    if(!flag){
        cout << "-1\n";
        return 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
    
    
    
    return 0;
}
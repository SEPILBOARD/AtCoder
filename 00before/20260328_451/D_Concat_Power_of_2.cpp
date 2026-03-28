#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;
#define INF 1'000'000'000

ll pw10[11];
ll pw2[40];
int len[40];

vector<int> ans;
set<int> v;

int main()
{
    FASTIO;
    pw10[0] = 1LL;
    for(int i = 1; i<=10; i++) pw10[i] = pw10[i-1]*10LL;

    queue<int> q;
    q.push(1);
    v.insert(1);
    ans.push_back(1);

    pw2[0] = 1LL;
    len[0] = 1;
    for(int i = 1; i<30; i++){
        pw2[i] = pw2[i-1]*2LL;
        
        q.push(pw2[i]);
        v.insert(pw2[i]);
        ans.push_back(pw2[i]);

        int cur = pw2[i];
        while(cur){
            len[i]++;
            cur /= 10;
        }
    }

    while(!q.empty()){
        ll cur = q.front();
        q.pop();

        for(int i = 0; i<30; i++){
            ll nxt = cur*pw10[len[i]] + pw2[i];
            if(nxt>INF) continue;
            if(v.count(nxt)) continue;

            q.push(nxt);
            v.insert(nxt);
            ans.push_back(nxt);
        }
    }
    
    sort(ans.begin(), ans.end());

    int n;
    cin >>n;
    cout << ans[n-1];

    return 0;
}
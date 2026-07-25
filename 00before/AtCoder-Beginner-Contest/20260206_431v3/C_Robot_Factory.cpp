#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, m, k;
priority_queue<int, vector<int>, greater<>> h;
priority_queue<int, vector<int>, greater<>> b;


int main()
{
    FASTIO;
    cin >> n >> m >> k;
    for(int i = 0; i<n; i++){
        int hi; cin >> hi;
        h.push(hi);
    }
    for(int i = 0; i<m; i++){
        int bi; cin >> bi;
        b.push(bi);
    }

    int cnt = 0;
    while(cnt<k && !b.empty()){
        int hi = h.top();
        int bi = b.top();
        b.pop();

        if(hi>bi){
            // cout << bi <<"n\n";
            continue;
        }

        h.pop();
        cnt++;

        // cout << hi <<", " << bi <<"\n";
    }

    if(cnt>=k){
        cout << "Yes\n";
    }
    else cout << "No\n";
    
    return 0;
}
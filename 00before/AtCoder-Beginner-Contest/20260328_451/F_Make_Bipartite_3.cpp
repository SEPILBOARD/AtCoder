#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

struct Node
{
    int p;
    int c;
};

class DSU
{
    private:
        vector<Node> node;
        vector<int> cnt0;
        vector<int> cnt1;

    public:
        ll ans = 0;
        DSU(int n)
        {
            node.resize(n+1);
            cnt0.resize(n+1, 1);
            cnt1.resize(n+1, 0);
            for(int i = 1; i<=n; i++){
                node[i] = {i, 0};
            }
            ans = 0;
        }

        Node Find(int x)
        {
            if(node[x].p == x) return node[x];
            else{
                auto[p, c] = Find(node[x].p);
                node[x].p = p;
                node[x].c ^= c;

                return node[x];
            }
        }

        void Union(int x, int y)
        {
            auto[xp, xc] = Find(x);
            auto[yp, yc] = Find(y);
            
            if(xp == yp) return;

            ans -= min(cnt0[xp], cnt1[xp]);
            ans -= min(cnt0[yp], cnt1[yp]);

            int dif = xc^yc^1;
            if(dif == 0){
            cnt0[yp] += cnt0[xp];
            cnt1[yp] += cnt1[xp];
            }
            else{
                cnt0[yp] += cnt1[xp];
                cnt1[yp] += cnt0[xp];
            }

            node[xp].c = dif;
            node[xp].p = yp;

            ans += min(cnt0[yp], cnt1[yp]);
        }
};

int main()
{
    FASTIO;
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    bool flag = true;
    for(int i = 0; i<q; i++){
        int x, y;
        cin >> x >> y;

        if(!flag){
            cout << "-1\n";
            continue;
        }
        
        Node xn = dsu.Find(x);
        Node yn = dsu.Find(y);
        
        if(xn.c == yn.c){
            cout << "-1\n";
            flag = false;
            continue;
        }

        cout << dsu.ans <<"\n";
    }
    

    return 0;
}
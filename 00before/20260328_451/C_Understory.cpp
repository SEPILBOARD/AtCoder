#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int n, q, h;
multiset<int> st;

int main()
{
    FASTIO;
    
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> q >> h;

        if(q == 1){
            st.insert(h);
        }
        else{
            auto it = st.upper_bound(h);
            st.erase(st.begin(), it);
        }

        cout << st.size() << "\n";
    }
    return 0;
}
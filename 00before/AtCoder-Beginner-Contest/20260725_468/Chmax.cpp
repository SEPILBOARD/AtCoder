#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

int x, y, c;

int main()
{
    FASTIO;
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    x = a[0];
    c++;
    vector<int> stk;
    stk.push_back(-1);
    for(int i = 1; i<n; i++){
        if(y>x){
            stk.clear();
            stk.push_back(x);
            swap(x, y);
        }
        if(x<a[i]){
            x = a[i];
            c++;
        }
        else{
            if(stk.back()<a[i]){
                c++;
            }
            while(stk.back()>a[i] && stk.size()>1) stk.pop_back();
            stk.push_back(a[i]);
        }
    }

    cout << c << "\n";
    
    return 0;
}
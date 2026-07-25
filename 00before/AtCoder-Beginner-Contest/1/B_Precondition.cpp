#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

string s, t;
set<char> ext;

int main()
{
    FASTIO;
    cin >> s;
    cin >> t;

    for(char c: t){
        ext.insert(c);
    }

    for(int i = 1; i<s.length(); i++){
        if('A'<=s[i] && s[i]<='Z'){
            if(ext.count(s[i-1])) continue;
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
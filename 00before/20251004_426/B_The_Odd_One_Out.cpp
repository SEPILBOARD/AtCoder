#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

string s;
int cnt[26];

int main()
{
    FASTIO;
    cin >> s;
    for(char c: s){
        cnt[c-'a']++;
    }

    for(int i = 0; i<26; i++){
        if(cnt[i] == 1){
            cout << char('a'+i);
            return 0;
        }
    }

    return 0;
}
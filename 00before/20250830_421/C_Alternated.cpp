#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n;
string s;
vector<int> idx;

int main()
{
    FASTIO;
    cin >> n >> s;

    for(int i = 0; i<2*n; i++){
        if(s[i] == 'A') idx.push_back(i);
    }

    long long int aans = 0;
    long long int oans = 0;
    int widx = 0;
    for(int i: idx)
    {
        oans += abs(widx+1 - i);
        aans += abs(widx - i);
        widx += 2;
    }
    cout << min(oans, aans);

    return 0;
}
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;

int n, h, m;
pair<int, int> ab[3001];
struct Compare1
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return min(a.first, a.second) > min(b.first, b.second);
    }
};

struct Compare2
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

struct Compare3
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Compare1> pq;

int main()
{
    FASTIO;
    cin >> n >> h >> m;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    while(!pq.empty()){
        auto [a, b] = pq.top();
        if(a>h && b>m) break;
        pq.pop();
        if(a>b);
 
    }
    

    return 0;
}
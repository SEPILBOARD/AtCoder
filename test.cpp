//
// Created by Jiwon Sheen on 2025. 10. 25.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void fastIo() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

using ll = long long;

int main() {
    int n, c;
    ll m;
    ll ans = 0;
    vector<ll> v, vs;
    vector<int> pcnt;

    fastIo();

    cin >> n >> m >> c;

    v.resize(n);

    for (auto &val: v) {
        cin >> val;
        vs.push_back(val);
    }

    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());

    pcnt.resize(vs.size() << 1);

    for (const auto &val: v) {
        const int idx = lower_bound(vs.begin(), vs.end(), val) - vs.begin();
        pcnt[idx]++;
        pcnt[idx + vs.size()]++;
    }

    for (int i = 1; i < pcnt.size(); i++)
        pcnt[i] += pcnt[i - 1];

    for (ll i = 0, pre = -(m - vs.back()); i < vs.size(); i++) {
        const auto &cur = vs[i];
        ll ca = n;

        for (int left = 1, right = vs.size(); left <= right;) {
            int mid = (left + right) >> 1;

            if (pcnt[i + mid] - pcnt[i] >= c) {
                ca = pcnt[i + mid] - pcnt[i];
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        ans += ca * (cur - pre);
        pre = cur;
    }

    cout << ans << '\n';

    return 0;
}
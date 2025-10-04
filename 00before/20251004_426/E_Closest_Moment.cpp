#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
};

double dot(Point a, Point b){ return a.x*b.x + a.y*b.y; }
double norm2(Point a){ return dot(a,a); }
double dist(Point a, Point b){ return sqrt(norm2(a-b)); }
double clampd(double v, double lo, double hi){ return max(lo, min(hi, v)); }

void solve()
{
    Point ts, tg, as, ag;
    cin >> ts.x >> ts.y >> tg.x >> tg.y;
    cin >> as.x >> as.y >> ag.x >> ag.y;

    double lt = dist(ts, tg);
    double la = dist(as, ag);

    Point vt = (tg-ts)*(1/lt);
    Point va = (ag-as)*(1/la);

    double ans = norm2(tg-ag);

    double t0;
    double tans;
    
    double m = min(lt, la);
    Point d0 = ts-as;
    Point dv = vt-va;
    t0 = clampd(-1*dot(d0, dv) / norm2(dv), 0, m);
    ans = min(ans, tans);


    if(lt < la){
        Point a = tg-as;
        Point v = Point(-1*va.x, -1*va.y);
        double A = lt;
        
    }


}

int main()
{
    FASTIO;
    cout.precision(10);
    int _tc; cin >> _tc;
    while(_tc--) solve();
    return 0;
}
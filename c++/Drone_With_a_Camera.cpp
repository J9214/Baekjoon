#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef struct Point {ll x, y, c;} point;
#define modulo 1000000007

ll gcd(ll a, ll b)
{
	ll c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

double inter(point l, point m){
    double lc = lcm(l.x , m.x);
    double lcl = lc/l.x;
    double lcm = lc/m.x;

    double dly = l.y * lcl, dlc = l.c * lcl;
    double dmy = m.y * lcm, dmc = m.c * lcm;

    double dy = dly - dmy, dc = dlc - dmc;
    double y = dc / dy;
    double x = (l.c - l.y * y) / l.x;
    
    return sqrt(pow(x,2)+pow(y,2));
}

int main(){
    FASTIO

    point x,y;
    double a,b,c,d,e,f;cin >> a >> b >> c >> d >> e >> f;
    x={a,b,c};
    y={d,e,f};

    cout << fixed;
    cout.precision(12);
    cout << inter(x,y);
}
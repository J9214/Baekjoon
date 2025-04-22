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
#define modulo 1000000007

struct Point{
    ll x, y;
    bool operator < (const Point &a){
        return y == a.y ? x < a.x : y < a.y;
    }
};
vector<Point> p(100001);
ll ccw(const Point &a, const Point &b, const Point &c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
ll dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool cmp(const Point &a, const Point &b){
    ll c = ccw(p[0], a, b);
    if(c == 0) return dist(p[0], a) < dist(p[0], b);
    return c > 0;
}
vi s(100001);
int top = 0;
void push(ll n){s[top++] = n;}

int main(){
    FASTIO

    ll n ; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int a, b; cin >> a >> b;
        p[i] = {a,b};
    }

    sort(p.begin(), p.begin()+n);
    sort(p.begin() + 1, p.begin()+n, cmp);
    push(0);
    push(1);

    for(int i = 2; i < n; i++){
        while(top >= 2 && ccw(p[s[top-2]], p[s[top-1]],p[i])<=0) top--;
        push(i);
    }

    cout << top << '\n';
}
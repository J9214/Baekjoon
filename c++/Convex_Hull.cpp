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
        return y != a.y ? x < a.x : y < a.y;
    }
};
vector<Point> vec;
vector<Point> p(100001);
ll ccw(const Point &a, const Point &b, const Point &c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
ll dist(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
bool cmp(const Point &a, const Point &b){
    ll c = ccw(vec[0], a, b);
    if(c == 0) {
       return dist(vec[0], a) < dist(vec[0], b);
    }
    return c > 0;
}

int main(){
    FASTIO

    ll n ; cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        ll a, b; cin >> a >> b;
        char c; cin >> c;
        if(c=='Y') vec.push_back({a,b});
    }

    sort(vec.begin(), vec.end(), [](Point &a, Point &b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });
    sort(vec.begin() + 1, vec.end(), cmp);
    vector<Point> R;
    vector<Point> A;
    
    
    for(ll i = 0; i < vec.size(); i++){
        while(A.size() >= 2 && ccw(A[A.size()-2], A.back(),vec[i])<0) {
            R.push_back(A.back());
            A.pop_back();
        }
        A.push_back(vec[i]);
    }
    for(ll i = R.size() - 1; i >= 0; i--)  
        A.push_back(R[i]);
    
    cout << A.size() << '\n';
    for(ll i = 0;  i < A.size(); i++){
        cout << A[i].x << ' ' << A[i].y << '\n';
    }
}
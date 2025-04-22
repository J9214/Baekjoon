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
typedef struct Point {double x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define modulo 1000000007

int main(){ 
    FASTIO

    double n; cin >> n;
    vector<point> vec;
    double cx = 0, cy = 0, w = 0.1;
    for(int i = 0 ; i < n ; i++){
        double x,y;cin >> x >> y;
        vec.push_back({x,y});
        cx += x / n;
        cy += y / n;
    }

    double mxdist;
    for(int i= 0 ; i < 100000; i++){
        mxdist = 0; point mxPoint;
        for(int j = 0 ; j < n ; j++){
            double dist = sqrt(pow(vec[j].x - cx, 2)+pow(vec[j].y - cy, 2));
            if(dist > mxdist){
                mxdist = dist;
                mxPoint.x = vec[j].x;
                mxPoint.y = vec[j].y;
            }    
        }       
        cx = cx + (mxPoint.x - cx) * w;
        cy = cy + (mxPoint.y - cy) * w;
        
        w *= 0.9995;
    }
    cout << fixed;
    cout.precision(2);

    cout << mxdist * 2;    
}
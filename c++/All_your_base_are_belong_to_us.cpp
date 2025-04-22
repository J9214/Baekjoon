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
#define modulo 1000000007

int main(){
    FASTIO

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<point> vec;
        double cx=0,cy=0,w=0.3;
        for(int i = 0; i < n ; i ++){
            double a, b; cin >> a >> b;
            vec.push_back({a, b});
            cx+=a/n;
            cy+=b/n;
        }
        vector<double> dVec(n);
        for(int i = 0 ; i < 1000000 ; i ++){
            for(int j = 0 ; j < vec.size() ; j++){
                dVec[j] = sqrt(pow(vec[j].x - cx, 2) + pow(vec[j].y - cy, 2));
            }
            
            double dx,dy;
            for(int j = 0 ; j < n ; j++){
                if(dVec[j]) {
                    dx += (cx - vec[j].x) / dVec[j];
                    dy += (cy - vec[j].y) / dVec[j];
                }
            }

            cx = cx - dx * w;
            cy = cy - dy * w;

            w *= 0.9999;
        }
        cout<<fixed;
        cout.precision(6);
        cout << cx << ' ' << cy << '\n';
        
    }
    
}
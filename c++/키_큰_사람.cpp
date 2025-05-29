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
typedef struct Point {int x, y;} point;
point direction[4] = {{1,0},{0,1},{-1,0},{0,-1}};
#define X first
#define Y second
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

int main(){
    FASTIO

    int c=0;
    while(1){
        int n; cin >> n;
        if(!n) break;
        vector<tuple<double, int, string>> vec;
        while(n--){
            string s; cin >> s;
            double d; cin >> d;
            vec.push_back({d,c++,s});
        }
        sort(vec.begin(),vec.end(),[](const tuple<double, int, string> &a, const tuple<double, int, string> &b){
            if(get<0>(a) == get<0>(b)) return get<1>(a) < get<1>(b);
            return get<0>(a) > get<0>(b);
        });
        
        for(int i = 0 ; i< vec.size() ; i++){
            if(i&&get<0>(vec[i])!=get<0>(vec[i-1]))break;
            cout << get<2>(vec[i]) << ' ';
        }
        cout << '\n';
    }
    
}
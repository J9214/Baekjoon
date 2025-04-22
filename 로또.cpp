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

vi res(6);
vi vec;

void combi(int d, int idx){
    if(d == 6) {
        print(res);
        cout << '\n';
        return;
    }
    
    for(int i = idx; i<vec.size();i++){
        res[d] = vec[i];
        combi(d+1,i+1);
    }

}
int main(){
    FASTIO

    while(1){
        int n ;cin >> n; 
        if(!n) break;
        vec.clear();
        for(int i = 0 ; i < n ; i++){
            int d; cin >> d;
            vec.push_back(d);
        }
        
        combi(0,0);
        cout << '\n';
    }
}
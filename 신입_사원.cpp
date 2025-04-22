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
void print(vpi vec){for(auto i : vec) cout << i.first << ' ' << i.second<< '\n';}
#define modulo 1000000007

int main(){
    FASTIO

    int t;cin>>t;
    while(t--){
        int n; cin >> n;
        vpi vec(n);
        for(int i =0  ; i <n ; i++){
            int a,b;cin>>a>>b;
            vec[i] = {a,b};
        }
        sort(vec.begin(),vec.end(),[](pi &a, pi &b){
            if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        });
        
        int c = 0;
        int m = n+1;
        for(int i=  0 ; i < n ; i++){
            if(vec[i].second < m) {
                m = vec[i].second;
                c++;
            }
        }
        cout << c;
        cout << '\n';
    }

}   
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
    int n;cin>>n;
    vvi vec(n,vi(n));
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j <n ; j++){
            char c;cin>>c;
            if(c=='.')vec[i][j]=1;
            else vec[i][j]=0;
        }
    }

    int w=0,h=0;
    for(int i = 0 ; i< n ; i++){
        int l=0;
        for(int j = 0 ; j <n ; j++){
            if(vec[i][j]) l++;
            if(!vec[i][j] || j == n-1){
                if(l>=2) w++;
                l=0;
            }
        }
    }

    for(int i = 0 ; i< n ; i++){
        int l=0;
        for(int j = 0 ; j <n ; j++){
            if(vec[j][i]) l++;
            if(!vec[j][i] || j == n-1){
                if(l>=2) h++;
                l=0;
            }
        }
    }
    cout << w << ' ' << h;
}
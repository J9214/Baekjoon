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
    
    vi vec(8);
    vector<bool> visited(14,0);
    int n1,n2,n3,n4,n5,n6,n7;
    for(int a=1; a<=13; a++){
        n1 = vec[3] - a;
        if(!n1) {
            continue;
        for(int b=1; b<=13; b++){
            n2 = vec[7]-b1;
            for(int c=1; c<=13; c++){
                for(int d=1; d<=13; d++){
                    for(int e=1; e<=13; e++){
                        for(int f=1; f<=13; f++){
        
                        }
                    }
                }
            }
        }   
    }
}
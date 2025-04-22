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
void print(vll vec){for(auto i : vec) cout << i << ' ';}
#define modulo 1000000007

ll power(ll a, ll b, ll c, ll d, ll e){
    return (a)* (100 +b ) * (100 * (100 - min(c,(ll)100)) + min(c,(ll)100) * d) * (100 + e);
}
int main(){
    FASTIO
    vll vec1(5),vec2(5);
    ll a=0,b=0,c=0,d=0;
    for(int i = 0;  i < 5; i++)
        cin >> vec1[i];
    for(int i = 0;  i < 5; i++)
        cin >> vec2[i];
    a=power(vec1[0],vec1[1],vec1[2],vec1[3],vec1[4]);
    b=power(vec2[0],vec2[1],vec2[2],vec2[3],vec2[4]);
    vll vec3(5,0),vec4(5,0);
    for(int i = 0;  i < 5; i++)
        cin >> vec3[i];
    for(int i = 0;  i < 5; i++)
        cin >> vec4[i];
    for(int i = 0;  i < 5; i++){
        vec1[i] += vec4[i] -vec3[i];
        vec2[i] += vec3[i] - vec4[i];
    }
    c=power(vec1[0],vec1[1],vec1[2],vec1[3],vec1[4]);
    d=power(vec2[0],vec2[1],vec2[2],vec2[3],vec2[4]);
    if(a<c)cout << "+";
    else if(a==c)cout << "0";
    else cout << "-";
    cout << '\n';
    if(b<d)cout << "+";
    else if(b==d)cout << "0";
    else cout << "-";
}
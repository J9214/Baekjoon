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

    long double total=365, curr=0;
    string m, s; cin >> m;
    if(m == "February")curr += 31;
    if(m == "March")curr +=59;
    if(m == "April")curr += 90;
    if(m == "May")curr += 120;
    if(m == "June")curr += 151;
    if(m == "July")curr += 181;
    if(m == "August")curr += 212;
    if(m == "September")curr += 243;
    if(m == "October")curr += 273;
    if(m == "November")curr += 304;
    if(m == "December")curr += 334;
    curr *= 24*60;

    cin >> s;
    curr += (stold(s.substr(0,2))-1) * 24*60;

    cin >> s;
    int y = stoi(s);
    if(!(y%400) || (!(y%4) && y%100)){
        if(!(m == "January" || m == "February")){
            curr+=24*60;
            total = 366;
        }
    }

    total *= 24*60;
    cin >> s;
    curr += stold(s.substr(0,2))*60 + stold(s.substr(3,2));

    cout << fixed;
    cout.precision(12);
    cout << curr * 100 / total;

}
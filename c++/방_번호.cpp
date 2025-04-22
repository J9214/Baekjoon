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
#define modulo 1000000007

int main(){
    FASTIO

    int n; cin >> n;
    vector<double> vec(10,0);
    while(n){
        vec[n%10]++;
        n/=10;
    }
    vec[6] = ceil((vec[6] + vec[9]) / 2);
    vec[9] = 0;
    int m = 0;
    for(int i = 0 ; i< 10;i++)
        m = max(m, int(vec[i]));
    cout << m;
}
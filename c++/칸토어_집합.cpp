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

void kantour(int d){
    if(d == 0) {
        cout << '-';
        return;
    }

    kantour(d - 1);
    for(int i = 0 ; i < pow(3, d - 1); i++)
        cout << ' ';
    kantour(d - 1);
}

int main(){
    FASTIO
    
    int n;

    while(cin >> n){
        kantour(n);
        cout << '\n';
    }
}
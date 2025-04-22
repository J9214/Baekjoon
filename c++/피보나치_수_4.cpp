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
void print(vector<string> vec){for(auto i : vec) cout << i << '\n';}
#define modulo 1000000007

string ssum(string a, string b){
    int i=0;
    while(i < a.size()){
        b[b.size() -1 - i] +=a[a.size() - 1 - i]-'0';
        if(b[b.size() -1 - i]>'9') {
            b[b.size() -1 - i]-=10;

            if(((int)b.size() - 2 -i)>=0)  b[b.size() -2 - i]++;
            else b.insert(0,"1");
        }
        i++;
    }
    
    return b;
}

int main(){
    FASTIO

    int n ; cin >> n;
    vector<string> vec(2);
    vec[0]="0";
    vec[1]="1";
    
    for(int i = 2; i <= n; i++)
        vec.push_back(ssum(vec[i-2],vec[i-1]));
    
    cout << vec[n];
}
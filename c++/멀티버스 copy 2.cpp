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

int main(){
    FASTIO
    int n, m; cin >> n >> m;
    vector<string> vec;
    int prev, curr;
    for(int i = 0;  i < n ; i++){
        string s="";
        for(int j = 0 ; j < m ; j++){
            cin >> curr;
            if(j){
                if(prev==curr) s+="1";
                else if(prev<curr) s+="0";
                else s+="2";
            }
            
        }
        vec.push_back(s);
    }        
    sort(vec.begin(),vec.end());

    int res=0;
    for(int i =  0;  i< vec.size()-1 ; i++) 
        if(vec[i]==vec[i+1]) res++;

    print(vec);
    // cout << vec.size() << '\n';
    cout << res;
}
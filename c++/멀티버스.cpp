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
    vpi vec2;
    int prev, curr;
    for(int i = 0;  i < n ; i++){
        vec2.clear();
        string s="";

        for(int j = 0 ; j < m ; j++){
            cin >> curr;
            if(j){
                if(prev==curr) s+="1";
                else if(prev<curr) s+="0";
                else s+="2";
            }
            vec2.push_back({curr,j});
        }

        sort(vec2.begin(),vec2.end(),[](pi &a, pi &b){
            return a.first < b.first;
        });
        int idx=0;

        for(int v = 0 ; v < vec2.size() ; v++) {
            if(v && vec2[v-1].first != vec2[v].first) idx++;
            s+= to_string(idx) + to_string(vec2[v].second);
        }
        vec.push_back(s);
    }        
    
    sort(vec.begin(),vec.end());

    int res=0;
    int t = 1;
    for(int i =  1;  i< vec.size() ; i++) {
        if(vec[i] == vec[i-1])t++;
        if(i==vec.size()-1 || vec[i]!=vec[i-1]) res += t*(t-1)/2,t=1;
    }

    cout << res;
}
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

struct cmp{
    bool operator()(pair<ll, char> &a, pair<ll, char> &b){
        return a.first < b.first;
    }
};
int main(){
    FASTIO
    ll n; cin >> n;
    ll t = 9;
    vector<string> vec;
    vector<ll> chk(26,0);
    priority_queue<pair<ll, char>, vector<pair<ll, char>>, cmp> pq;
    while(n--){
        string str; cin >> str;
        for(ll i =0 ; i < str.size() ; i++){
            chk[str[i]-'A'] += pow(10,ll(str.size() - i-1));
        }
        vec.push_back(str);
    }
	for(ll i = 0 ; i < chk.size(); i++){
		if(chk[i]) 
			pq.push({chk[i], i + 'A'});
	}


    while(!pq.empty()){
        for(ll i = 0 ; i < vec.size() ; i++){
            while(vec[i].find(pq.top().second)<vec[i].size()) vec[i].replace(vec[i].find(pq.top().second), 1, to_string(t));
        }
        pq.pop();
        t--;
    }
    
    ll res=0;
    for(ll i = 0 ; i< vec.size() ; i++){
        res += stoi(vec[i]);
    }
    cout << res;
}
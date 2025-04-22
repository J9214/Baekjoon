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
void print(vvi mat){for(auto i : mat){for(auto j : i) cout << j << ' ';cout << '\n';}}
void print(vi vec){for(auto i : vec) cout << i << ' ';}

void vecswap(vpi &a, vpi &b){
    vpi t;
    t = a;
    a = b;
    b = t;
}
int main(){
    FASTIO
    int t = 4;
    while(t--){
        vpi s1(4);
        vpi s2(4);
        int a,b,c,d;cin>>a>>b>>c>>d;
        s1[0] = {a,b};
        s1[1] = {a,d};
        s1[2] = {c,b};
        s1[3] = {c,d};
        cin>>a>>b>>c>>d;
        s2[0] = {a,b};
        s2[1] = {a,d};
        s2[2] = {c,b};
        s2[3] = {c,d};
        
        // sort(s1.begin(),s2.begin(), [](pi &a, pi &b){
        //     if(a.first == b.first) return a.second < b.second;
        //     return a.first < b.first;
        // });
        if(s1[0].first > s2[0].first) vecswap(s1,s2);
        if(s1[0].first <= s2[0].first){ // s2의 왼쪽 변이 s1의 왼쪽 변보다 오른쪽에 있다
            if(s1[3].first<s2[0].first) cout << "d"; // s1의 오른쪽 변보다 s2의 왼쪽변이 더 옆에 있다.
            else if(s1[2].second > s2[1].second) cout << "d"; // s2가 s1 위로   
            else if(s1[1].second < s2[0].second) cout << "d"; // s1이 s2위로  
            else if(s1[2].second == s2[1].second){
                if(s1[2].first == s2[1].first) cout << 'c';
                else cout << 'b';
            }
            else if(s1[1].second == s2[0].second){
                if(s1[2].first == s2[0].first) cout << 'c';
                else cout << 'b';
            }
            else {
                if(s1[3].first == s2[0].first){
                    if(s1[3].second == s2[0].second || s1[2].second == s2[1].second) cout << "c";
                    else cout << "b";
                }
                else cout << "a";
            }
        }
        cout << '\n';
    }
}
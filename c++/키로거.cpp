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

    while(n--){
        list<char> lt;
        string s; cin >> s;
        auto idx = lt.begin();
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '<'){
                if(idx != lt.begin())
                    idx--;
            }
            else if(s[i] == '>'){
                if(idx != lt.end())
                    idx++;
            }
            else if(s[i] == '-') {
                if(idx != lt.begin()){
                    idx--;
                    idx = lt.erase(idx);
                }
            }
            else lt.insert(idx, s[i]);
        }
        for(char c : lt) cout << c;
        cout << '\n';
    } 
    

}
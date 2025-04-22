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
void print(vector<char> vec){for(auto i : vec) cout << i;}
int main(){
    string str;getline(cin,str);
    vector<char> t;
    stack<char> s;
    for(char c : str){
        if(c == '<' || c == ' ') {
            while(!s.empty()) {
                cout << s.top();
                s.pop();
            }
            if(!t.size() && c==' ') {
                cout << ' ';
                continue;
            }
        }
        if(c=='>') {
            t.push_back(c);
            print(t);
            t.clear();
        }
        else if(c == '<' || t.size()) t.push_back(c);
        else s.push(c);
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}
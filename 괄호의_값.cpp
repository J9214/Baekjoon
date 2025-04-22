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

    stack<int> st;
    stack<char> chk;
    st.push(1);
    string s; cin >> s;
    for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] != '(' && s[i] != '[' && s[i] != ']' && s[i] != ')'){
            cout << 0; return 0;
        }
        if(s[i] == ')'|| s[i] == ']') {
            if(chk.empty() || abs(s[i]-chk.top()) > 2){
                cout << 0; return 0;
            }
            chk.pop();
        }
        else chk.push(s[i]);

        if(s[i] == '(') {
            if(i && (s[i-1] == ')' || s[i-1]==']')) st.push(0);
            st.push(2);
        }
        else if(s[i] == '[') {
            if(i && (s[i-1] == ')' || s[i-1]==']')) st.push(0);
            st.push(3);
        }


        if(s[i] == ')'|| s[i] == ']'){
            if(i && abs(s[i] - s[i-1]) >0 && abs(s[i] - s[i-1]) <= 2) st.push(1); 

            int a = st.top(); st.pop();
            if(st.top() == 0) {
                st.pop();
                a += st.top(); st.pop();
                st.push(a); 
            }
            else {
                a *= st.top(); 
                st.pop();
                st.push(a);
            }
        }

        if(chk.empty()){
            while(st.size()>1){
                int a = st.top(); st.pop();
                if(st.top() == 0) {
                    st.pop();
                    int b = st.top(); st.pop();
                    st.push(a+b); 
                }
                else {
                    a *= st.top(); 
                    st.pop();
                    st.push(a);
                }
            }
        }
    }
    
    if(!chk.empty()) cout << 0;
    else cout << (int)st.top();
}
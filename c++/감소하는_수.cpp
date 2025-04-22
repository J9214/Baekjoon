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

int n, cnt = -1;

void func(string s, int l){
    for(char c = '0'; c <= '9'; c++){
        if(s.size() >= l || (s.size() && s[s.size()-1] <= c)) break; // 못붙이면 
        string t = s + c;
        if(t.size() == l) cnt++;
        if(cnt == n) {
            cout << t << '\n';
            exit(0);
        }
        func(t, l);
    }
}
int main(){
    FASTIO

    cin >> n;
    string s ="";
    for(int l = 1 ; l <= 10; l++)
        func("", l);
    if(cnt < n) cout << -1;
}

// int main(){
//     FASTIO
//     int n; cin >> n;
//     string str = "9876543210";
//     int idx = 0, cnt = -1;

//     while(idx <= 10){ //자릿수 올리기
//         idx++;
//         string s = str.substr(10 - idx , idx);

//         if(cnt == n) {
//             cout << s;
//             exit(0);
//         }

//         cnt++;

//         while(idx==1||s[idx-2] != s[idx-1]) {// 첫 자리가 앞 자리랑 같지 않을 동안
//             cout << idx <<  ' ' << cnt <<  ' ' << s << '\n';
//             cnt++;
//             s[idx-1]++;   
            
//             if(cnt == n) {
//                 cout << s;
//                 exit(0);
//             }
            
//             int t=0;
//             while(idx > 1 && idx > t && s[idx-t-1] == s[idx-t]){ // 자릿수 올리기
//                 if(s[idx-t-1] == '9') break;
//                 s[idx-t-1]++;
//                 t++;
//                 s[idx] = '0';
//             }
//             if(s[idx-1-t] == '9') break; 
//         }

        
//     }
//     cout << -1;
// }
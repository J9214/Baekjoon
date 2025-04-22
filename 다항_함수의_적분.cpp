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

    string str; cin >> str;
    stringstream ss;
    bool x = false;
    
    if(str == "0") {
        cout << "W";
        return 0;
    }

    for(char c : str){
        if(isdigit(c) || ispunct(c)) ss << c;
        else if(isalpha(c)) {
            x = true;
            ss << ' ';
        }
    }
    
    string s;
    int num;
    bool f = x;
    while(ss >> num){
        if(abs(num) > 0) {
            if(x) {
                if(abs(num / 2) == 1){
                    if(num / 2 == -1) cout << "-";
                } 
                else cout << num / 2;
                cout << 'x';
                x = false;
            }
            else {
                if(f && num > 0) cout << '+';
                if(abs(num) == 1){
                    if(num == -1) cout << "-";
                } 
                else cout << num;
            }
            cout << 'x';
        }
        else cout << 1;
    }
    
    cout << "+W";
}
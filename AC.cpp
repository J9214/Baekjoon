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

    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        int n; cin >> n;
        string str; cin >> str;
        stringstream ss;
        deque<int> d;

        for(char c : str){
            if(isdigit(c)) ss << c;
            else ss << ' ';
        }
        int num;
        while(ss >> num) d.push_back(num);

        bool fb = false;
        bool b = false;
        for(char c : s){
            if(c == 'R') fb = !fb;
            else {
                if(d.empty()){
                    b = true;
                    break;
                }
                if(fb) d.pop_back();
                else d.pop_front();
            }
        }
        if(b) {
            cout << "error\n";
            continue;
        }

        cout << "[";
        int f=0, e=d.size(), a = 1; 
        if(fb){
            f=d.size()-1;
            e=-1;
            a = -1;
        }
        while(f != e){
            cout << d[f];
            f += a;
            if(f != e) cout << ',';
        }
        cout << "]\n";
    }
}
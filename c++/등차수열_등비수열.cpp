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

        int n, m; cin >> n >> m;
        vll vec(n);
        map<ll,ll> a_m, g_m; 
        for(int i = 0;  i < n ; i++) cin >> vec[i];

        for(int i = 1 ; i < n ; i++){
            a_m[vec[i]-vec[i-1]]++;
            if(vec[i]%vec[i-1]==0)
                g_m[vec[i]/vec[i-1]]++;
        }
        while(m--){
            ll a,b; cin >> a >> b;
            // a==1일때 뒤 숫자랑만 비교
            // a==n일때 앞 숫자랑만 비교
            a--;
            if(a!=n-1) {
                a_m[vec[a+1]-vec[a]]--;
                a_m[vec[a+1]-b]++;
                if(a_m[vec[a+1]-vec[a]]==0) a_m.erase(vec[a+1]-vec[a]);
                if(vec[a] != 0 && vec[a+1]%vec[a]==0) {
                    ll r = vec[a+1]/vec[a];
                    g_m[r]--;
                    if(g_m[r]==0) g_m.erase(r);
                }
                if(vec[a+1]%b==0) g_m[vec[a+1]/b]++;
            }
            if(a!=0){
                a_m[vec[a]-vec[a-1]]--;
                a_m[b-vec[a-1]]++;
                if(a_m[vec[a]-vec[a-1]]==0) a_m.erase(vec[a]-vec[a-1]);
                if(vec[a-1]!=0 && vec[a]%vec[a-1]==0){
                    ll r = vec[a]/vec[a-1];
                    g_m[r]--;
                    if(g_m[r]==0) g_m.erase(r);
                } 
                if(b%vec[a-1]==0) g_m[b/vec[a-1]]++;
            }

            if(a_m.size()==1 && a_m.begin()->first > 0 && a_m[a_m.begin()->first]==n-1) cout << "+";
            else if(g_m.size()==1 && g_m.begin()->first >0 && g_m[g_m.begin()->first]==n-1) cout << "*";
            else cout << "?";
            cout << '\n';

            vec[a]=b;
        }
    }
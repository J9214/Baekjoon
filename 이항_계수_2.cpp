#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef struct Point {int x, y;} point;
point direction[3] = {{1,0},{0,1},{1,1}};
ll modulo = 10007;

ll mod_pow(ll base, ll exp){
    ll result = 1;
    
    if(!exp) return result;
    if(exp % 2) return (mod_pow(base, exp - 1) * base + modulo) % modulo;
    ll half =  (mod_pow(base, exp / 2) + modulo) % modulo;
        
    return (half * half + modulo) % modulo;
}

ll mod_inverse(ll base, ll modulo){
    return mod_pow(base, modulo - 2);
}

ll combination(ll n, ll k){
    if(k < 0 || n < k) return 0;
    if(n == k || !k) return 1;

    ll numerator = 1;
    ll denominator = 1;

    for(int i = 0; i < k; i++){
        numerator = ((numerator * (n - i)) + modulo) % modulo;
        denominator = ((denominator * (i + 1)) + modulo) % modulo;
    }

    ll inv = mod_inverse(denominator, modulo);

    return ((numerator * inv) + modulo) % modulo;
}

int main(){
    FASTIO
    
    ll n, k; cin >> n >> k;

    cout << combination(n, k) << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef vector<ll> vll;

ll square(vll &vec, int left, int right){
    if(left == right) return vec[left];

    int mid = (left + right) / 2;
    ll res = max(square(vec, left, mid), square(vec, mid + 1, right));
  
    int low = mid, high = mid + 1;
    ll height = min(vec[low], vec[high]);
    res = max(res, height * 2);

    while (left < low || high < right) {
        if (high < right && (low == left || vec[low - 1] < vec[high + 1])) {
            high++;
            height = min(height, vec[high]);
        } else {
            low--;
            height = min(height, vec[low]);
        }
        res = max(res, height * (high - low + 1));
    }

    return res;
}

int main(){
    FASTIO

    ll n;
    while(cin >> n){
        if(!n) break;
        vll vec(n);
        for(ll i = 0 ; i < n ; i++)
            cin >> vec[i];
        
        cout << square(vec, 0, vec.size() - 1) << '\n';
    }

    return 0;
}

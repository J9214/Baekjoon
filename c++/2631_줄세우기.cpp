#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    vi vec;
    int n ; cin >> n;
    for(int i = 0 ; i < n ; i++){
        int d; cin >> d;
        auto it = lower_bound(vec.begin(),vec.end(),d);
        if(it != vec.end()) *it = d;
        else vec.push_back(d);
    }
    cout << n - vec.size();
}
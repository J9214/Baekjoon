#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    int n,q; cin >> n >> q;
    vi tree(n+1,0);
    for(int i = 0 ; i < q; i++) {
        int t, res = 0; cin >> t;
        int t2 = t; // 점유할 땅의 번호
        while(t){
            if(tree[t] != 0) res = t;
            t/=2;
        }
        cout << res << '\n';
        tree[t2]++;
    }
}
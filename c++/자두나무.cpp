#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;

int main(){
    FASTIO

    int t,w;cin >> t >> w;
    vi plums;
    int prev, a, c=1; cin >> prev;
    for(int i = 0 ; i < t-1 ; i++){
        cin >> a;
        if(prev != a){
            plums.push_back(c);
            c = 1;
        }
        else c++;
        prev = a;
    }
    plums.push_back(c);

    int res = 0, m_=0;
    for(int i = 0 ; i < plums.size() ; i++){
        if(i - w > 0) res -= plums[i-w-1];
        res += plums[i];
        m_ = max(m_, res);
    }
    cout << m_;
}
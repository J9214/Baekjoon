#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FASTIO
    
    int n, m; cin >> n >> m;
    
    vector<int> pos, neg;
    while(n--){
        int d; cin >> d;
        if(d > 0) pos.push_back(d);
        else neg.push_back(-d);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int s = 0;
    if(neg.empty()){
        int i = pos.size() - m - 1;
        s += pos[pos.size() - 1];
        
        while(i >= 0){
            s += pos[i] * 2;
            i -= m;
        }
    }
    else if(pos.empty()){
        int i = neg.size() - m - 1;
        s += neg[neg.size() - 1];
        
        while(i >= 0){
            s += neg[i] * 2;
            i -= m;
        }
    }
    else if(pos[pos.size() - 1] < neg[neg.size() - 1]){
        int i = pos.size() - m - 1;
        s += pos[pos.size() - 1] * 2;
        
        while(i >= 0){
            s += pos[i] * 2;
            i -= m;
        }

        i = neg.size() - m - 1;
        s += neg[neg.size() - 1];
        
        while(i >= 0){
            s += neg[i] * 2;
            i -= m;
        }
    }
    else {
        int i = neg.size() - m - 1;
        s += neg[neg.size() - 1] * 2;
        
        while(i >= 0){
            s += neg[i] * 2;
            i -= m;
        }

        i = pos.size() - m - 1;
        s += pos[pos.size() - 1];
        
        while(i >= 0){
            s += pos[i] * 2;
            i -= m;
        }
    }
    cout << s;
    
        
    return 0;
}
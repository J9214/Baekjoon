#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, a, b;

    cin >> N >> M;
    vector<int> vec[N + 1];
    queue<int> seq;
    vector<int> start;
    int pre[N + 1]{0};
    bool chk[N + 1]{0};

    for(int i = 0;  i < M; i++){
        cin >> a >> b;    
        vec[a].push_back(b);
        pre[b]++;
    }

    vector<int> res;

    for(int i = 1; i <= N; i++){
        if(pre[i] == 0) seq.push(i);
    }

    for(int i = 1 ; i <= N; i++){
        if(seq.empty()) break;

        int x = seq.front();
        seq.pop();
        res.push_back(x);
    
            
        for(int j = 0 ; j < vec[x].size(); j++){
            if(--pre[vec[x][j]] == 0) seq.push(vec[x][j]);
        }
    }

    for(int i = 0 ; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}
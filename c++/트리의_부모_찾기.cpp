    #include <bits/stdc++.h>
    using namespace std;
    #define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    typedef long long ll;
    typedef pair<int, int> pi;
    typedef pair<ll, ll> pl;
    typedef vector<int> vi;
    typedef vector<pair<int, int>> vpi;
    typedef vector<vector<int>> vvi;
    typedef struct Point {int x, y;} point;
    point direction[3] = {{1,0},{0,1},{1,1}};

    int main(){
        FASTIO
        
        int n; cin >> n;
        vvi vec(n + 1);
        vector<bool> visit(n + 1, 0);
        vi parent(n+1,0);
        queue<pi> q;
        for(int i = 0 ;  i < n-1; i++){
            int a,b; cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        for(int i = 0 ; i< vec[1].size(); i++) q.push({1,vec[1][i]});
        visit[1] = 1;
        while(!q.empty()){
            int front = q.front().first;
            while(q.front().first == front){
                if(!visit[q.front().second]){
                    for(int i = 0 ; i< vec[q.front().second].size(); i++){
                        if(!visit[vec[q.front().second][i]])
                            q.push({q.front().second,vec[q.front().second][i]});
                    }
                }
                visit[q.front().second] = 1;
                parent[q.front().second] = front;
                
                q.pop();
            }
        }
        for(int i = 2; i <= n ; i++)
            cout << parent[i] << '\n';
        
        return 0;
    }
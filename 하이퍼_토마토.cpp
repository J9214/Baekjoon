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
    int a,b,c,d,e,f,g,h,i,j,k, data, v = 0, res, days = 0, cnt = 0;
    
    vi val(11);
    int size = 1;
    for(int t = 0 ; t < 11; t++){
        cin >> val[t];
        size *= val[t];
    }
        
    
    vi dir;

    for(int t= 1; t >= - 1; t-= 2){
        int tmp = t;
        for(int y = 0; y < val.size(); y++){
            dir.push_back(tmp);
            tmp *= val[y];
        }
    }
    
    vi direct;
    for(int i = 0; i < dir.size(); i++){
        if(dir[i] == dir[i-1] || !dir[i]) continue;
        direct.push_back(dir[i]);
    }
    vector<int> vec(1000000);
    queue<int> q;

    for (int q1 = 0; q1 < size; q1+=dir[10]) 
        for (int q2 = q1; q2 < q1 + dir[10]; q2+=dir[9]) 
            for (int q3 = q2; q3 < q2 + dir[9]; q3+=dir[8]) 
                for (int q4 = q3; q4 < q3 + dir[8]; q4+=dir[7]) 
                    for (int q5 = q4; q5 < q4 + dir[7]; q5+=dir[6]) 
                        for (int q6 = q5; q6 < q5 + dir[6]; q6+=dir[5]) 
                            for (int q7 = q6; q7 < q6 + dir[5]; q7+=dir[4]) 
                                for (int q8 = q7; q8 < q7 + dir[4]; q8+=dir[3]) 
                                    for (int q9 = q8; q9 < q8 + dir[3]; q9+=dir[2]) 
                                        for (int q10 = q9; q10 < q9 + dir[2]; q10+=dir[1]) 
                                            for (int q11 = q10; q11 < q10 + dir[1]; q11+=dir[0]) {
                                                cin >> data;
                                                vec[q11] = data;
                                                if(data == -1) v++;
                                                if(data == 1) {
                                                    q.push(q11);
                                                    cnt++;
                                                }
                                            }
                                        

    res = size - v;
    
    while(!q.empty()){
        int it = q.size();
        while(it--){
            int current = q.front();
            q.pop();
            
            for(int l = 0 ; l < direct.size(); l++){
                int next = current + direct[l];
            
                if(next < 0 || next >= size) continue;
                if(vec[next] == 1 || vec[next] == -1) continue;
                if((l != direct.size()/2-1 && l != direct.size()-1 ) && (next / abs(direct[l + 1])) != (current / abs(direct[l + 1]))) continue;
                q.push(next);
                vec[next] = 1;
                cnt++;   
            }
        }
            
        if(q.empty()) break;
        days++;
    }
    if(cnt == res) cout << days;
    else cout << -1;
}
    
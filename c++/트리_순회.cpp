#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void print(vector<char> vec){for(auto i : vec) cout << i;}

vector<char> post, pre, in;
void dfs(int node, vvi &vec){
    pre.push_back((char)(node+'A'));
    if(vec[node][0]>=0) dfs(vec[node][0], vec);
    in.push_back((char)(node+'A'));
    if(vec[node][1]>=0) dfs(vec[node][1], vec);
    post.push_back((char)(node+'A'));
}
int main(){
    FASTIO
    int n; cin >> n;
    char x,c;
    vvi arr(26);
    for(int i = 0 ; i < n; i++){
        cin >> x;
        for(int j = 0 ; j < 2; j ++){
            cin >> c;
            arr[x-'A'].push_back(c-'A');
        }
    }
    dfs(0,arr);
    print(pre); cout << '\n';
    print(in); cout << '\n';
    print(post);
}
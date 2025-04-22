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
#define modulo 1000000007
#define MAX_SIZE 1001

struct UnionFind {
    int root[MAX_SIZE];
    int rank[MAX_SIZE];
    int nodeCount[MAX_SIZE];

    UnionFind(int size) {
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 0;
            nodeCount[i] = 1;
        }
    }

    int find(int x) {
        if (root[x] == x) {
            return x;
        } else {
            return root[x] = find(root[x]);
        }
    }

    void union1(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (rank[x] < rank[y]) {
            root[x] = y;
        } else {
            root[y] = x; 
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    int union2(int x, int y){
        x = find(x);
        y = find(y);

        if(x != y) {
            root[y] = x;
            nodeCount[x] += nodeCount[y];
            nodeCount[y] = 1;
        }
        return nodeCount[x];
    }
};

int main(){
    FASTIO
    
    int n, m; cin >> n >> m;
    UnionFind uf(n + 1);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            int d; cin >> d;
            if(d) uf.union1(i + 1, j + 1);
        }
    }

    int res = 0;
    bool b= false;
    for(int i = 0 ; i < m; i++){
        int a; cin >> a;
        if(!res) res = uf.find(a);
        else {
            if(res != uf.find(a)){
                b = 1;
                break;
            }
        }
    }

    if(b) cout << "NO";
    else cout << "YES";
    
    return 0;
}
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
#define MAX_SIZE 1000001

struct UnionFind {
    int root[MAX_SIZE];
    int rank[MAX_SIZE];
    int nodeCount[MAX_SIZE];

    UnionFind() {
        for (int i = 0; i < MAX_SIZE; i++) {
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
    
    UnionFind uf;
    int n, m; cin >> n >> m;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        if(a){
            if(uf.find(b) == uf.find(c)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else uf.union1(b,c);
    }
}
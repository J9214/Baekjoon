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

int n;
void recur(int t){
    for(int i = 0 ; i < t * 4; i++) cout << '_';
    cout << "\"재귀함수가 뭔가요?\"\n";
    if(t==n){
        for(int i = 0 ; i < t * 4; i++) cout << '_';
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
        for(int i = 0 ; i < t * 4; i++) cout << '_';
        cout << "라고 답변하였지.\n";
        return;
    }
    for(int i = 0 ; i < t * 4; i++) cout << '_';
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    for(int i = 0 ; i < t * 4; i++) cout << '_';
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    for(int i = 0 ; i < t * 4; i++) cout << '_';
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    recur(t+1);
    for(int i = 0 ; i < t * 4; i++) cout << '_';
    cout << "라고 답변하였지.\n";

}
int main(){
    FASTIO

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    cout << "\"재귀함수가 뭔가요?\"\n";
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    recur(1);
    cout << "라고 답변하였지.\n";
    
}
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

string base;
string str;
vector<string> vec;

int chk(string a, string b){
    int c = 0;
    for(int i = 0 ; i < a.size(); i++){
        if(a[i] && b[i])  c++;
    }
    return c;
}

int recur(string a, int c){
    if(chk(base, str)) return c;
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
    int m_=0;
    vector<int> next;
    for(int i = 0 ; i < vec.size(); i++){
        int cnt = chk(str,vec[i]);
        if(cnt > m_){
            m_=cnt;
            next.clear();
            next.push_back(i);
        }
        else if(cnt == m_) next.push_back(i);
    }

    for(int i =0; i < next.size(); i++){
        string tmp = a;
        for(int j = 0 ; j < vec[next[i]].size(); j++)
            if(vec[next[i]][j] == 1) tmp[j] = 0;
        tmp[next[i]] = 1;
        recur(tmp, c++);
    }
}
int main(){
    FASTIO

    int n; cin >> n;
    base.resize(n, 0);
    base[2] = 1;

    cout << base;
    for(int i = 0 ; i< n ; i++){
        int d; cin >> d;
        str.push_back(d);
    }

    for(int i = 0; i < n ; i++){
        string t;
        t.resize(n,0);
        int c; cin >> c;
        for(int j = 0 ; j < c ; j++){
            int d; cin >> d;
            t[d] = 1;
        }
        vec.push_back(t);
    }

    cout << recur(str, 0);
}
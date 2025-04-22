#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pi;
typedef long long ll;
using pll=pair<ll,ll>;
using lb=long double;
lb get_dt(const pll &k1,const pll &k2){
    return lb(k2.Y-k1.Y)/lb(k2.X-k1.X);
}
int cross_line(ll y1,ll y2,ll y3,ll y4){
    if(y1>y2) swap(y1,y2);
    if(y3>y4) swap(y3,y4);
    if(y2<y3 or y4<y1) return false;
    return true;
}
bool is_valid(pll a1,pll a2,pll b1,pll b2){
    if(a2.X<b1.X or b2.X<a1.X){
        cout<<"0";
        return false;
    }
    if(max(a1.Y,a2.Y)<min(b1.Y,b2.Y) or max(b1.Y,b2.Y)<min(a1.Y,a2.Y)){
        cout<<"0";
        return false;
    }
    function<pair<bool,lb>(int,ll,ll,pll,pll)>sv=[](int target,ll l,ll r,pll k1,pll k2){
        if(l>r) swap(l,r);
        assert(k1.X<=k2.X);
        assert(k1.X<=target and target<=k2.X);
        pair<bool,lb>ret;
        lb y=lb(ll(target-k1.X)*ll(k2.Y-k1.Y))/lb(k2.X-k1.X)+lb(k1.Y);
        ll qt=(ll(target-k1.X)*ll(k2.Y-k1.Y))/ll(k2.X-k1.X)+k1.Y;
        ll res=(ll(target-k1.X)*ll(k2.Y-k1.Y))%ll(k2.X-k1.X);
        ret.first=false;
        if(l<=qt and qt<=r){
            //assert(floor(y)<=qt);
            if(qt==r and res>0) return ret;
            ret.X=true;
            if(res==0) ret.Y=qt;
            else ret.Y=y;
            //assert(ll(floor(y+lb(1e-7)))>=qt);
        }
        return ret;
    };
    if(a1.X==a2.X){
        if(b1.X==b2.X){
            if(cross_line(a1.Y,a2.Y,b1.Y,b2.Y)){
                cout<<"1\n";
                if(a1.Y>a2.Y) swap(a1,a2);
                if(b1.Y>b2.Y) swap(b1,b2);
                if(a1.Y==b2.Y){
                    cout<<a1.X<<" "<<a1.Y;
                }
                else if(b1.Y==a2.Y){
                    cout<<a1.X<<" "<<b1.Y;
                }
                //else many cross
            }
            else{
                assert(0);
                cout<<"0";
            }
        }
        else{
            auto y=sv(a1.X,a1.Y,a2.Y,b1,b2);
            if(y.first==true){
                cout<<"1\n";
                cout<<a1.X<<" "<<y.second;
            }
            else{
                cout<<"0";
            }
        }
        return false;
    }
    if(b1.X==b2.X){
        auto y=sv(b1.X,b1.Y,b2.Y,a1,a2);
        if(y.first==true){
            cout<<"1\n";
            cout<<b1.X<<" "<<y.second;
        }
        else{
            cout<<"0";
        }
        return false;
    }
    if(a1.Y==a2.Y){
        if(b1.Y==b2.Y){
            assert(a1.Y==b1.Y);
            cout<<"1\n";
            if(a1.X==b2.X){
                cout<<a1.X<<" "<<b1.Y;
            }
            else if(a2.X==b1.X){
                cout<<a2.X<<" "<<b1.Y;
            }
        }
        else{
            pll nb1={b1.Y,b1.X};
            pll nb2={b2.Y,b1.X};
            if(nb1.X>nb2.X) swap(nb1,nb2);
            auto x=sv(a1.Y,a1.X,a2.X,nb1,nb2);
            if(x.first==1){
                cout<<"1\n";
                cout<<x.second<<" "<<a1.Y;
            }
            else{
                cout<<"0";
            }
        }
        return false;
    }
    if(b1.Y==b2.Y){
        pll na1={a1.Y,a1.X};
        pll na2={a2.Y,a2.X};
        if(na1.X>na2.X) swap(na1,na2);
        auto x=sv(b1.Y,b1.X,b2.X,na1,na2);
        if(x.first==1){
            cout<<"1\n";
            cout<<x.second<<" "<<b1.Y;
        }
        else{
            cout<<"0";
        }
        return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    cout.precision(17);
    //freopen("input.txt", "r", stdin);
    pll a1,a2,b1,b2;cin>>a1.X>>a1.Y>>a2.X>>a2.Y>>b1.X>>b1.Y>>b2.X>>b2.Y;
    if(a1.X>a2.X) swap(a1,a2);
    if(b1.X>b2.X) swap(b1,b2);
    if(!is_valid(a1,a2,b1,b2)) return 0;
    lb a_dt=get_dt(a1,a2),b_dt=get_dt(b1,b2);
    int l=max(a1.X,b1.X),r=min(a2.X,b2.X);
    lb a_data=(l==a1.X?a1.Y:lb(a1.Y)+lb(ll(l-a1.X)*ll(a2.Y-a1.Y))/lb(a2.X-a1.X));
    lb b_data=(l==b1.X?b1.Y:lb(b1.Y)+lb(ll(l-b1.X)*ll(b2.Y-b1.Y))/lb(b2.X-b1.X));
    if(a_data<b_data){
        lb nxt_a_data=lb(a1.Y)+lb(ll(r-a1.X)*ll(a2.Y-a1.Y))/lb(a2.X-a1.X);
        lb nxt_b_data=lb(b1.Y)+lb(ll(r-b1.X)*ll(b2.Y-b1.Y))/lb(b2.X-b1.X);
        if(nxt_a_data<nxt_b_data){
            cout<<"0";
            return 0;
        }
        cout<<"1\n";
        ll x=(a1.X*a2.Y-a1.Y*a2.X)*(b1.X-b2.X)-(a1.X-a2.X)*(b1.X*b2.Y-b1.Y*b2.X);
        ll y=(a1.X*a2.Y-a1.Y*a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X*b2.Y-b1.Y*b2.X);
        ll m=(a1.X-a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X-b2.X);
        cout<<lb(x)/lb(m)<<" "<<lb(y)/lb(m);
    }
    else if(a_data>b_data){
        lb nxt_a_data=lb(a1.Y)+lb(ll(r-a1.X)*ll(a2.Y-a1.Y))/lb(a2.X-a1.X);
        lb nxt_b_data=lb(b1.Y)+lb(ll(r-b1.X)*ll(b2.Y-b1.Y))/lb(b2.X-b1.X);
        if(nxt_a_data>nxt_b_data){
            cout<<"0";
            return 0;
        }
        cout<<"1\n";
        ll x=(a1.X*a2.Y-a1.Y*a2.X)*(b1.X-b2.X)-(a1.X-a2.X)*(b1.X*b2.Y-b1.Y*b2.X);
        ll y=(a1.X*a2.Y-a1.Y*a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X*b2.Y-b1.Y*b2.X);
        ll m=(a1.X-a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X-b2.X);
        cout<<lb(x)/lb(m)<<" "<<lb(y)/lb(m);
    }
    else{
        cout<<"1\n";
        ll x=(a1.X*a2.Y-a1.Y*a2.X)*(b1.X-b2.X)-(a1.X-a2.X)*(b1.X*b2.Y-b1.Y*b2.X);
        ll y=(a1.X*a2.Y-a1.Y*a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X*b2.Y-b1.Y*b2.X);
        ll m=(a1.X-a2.X)*(b1.Y-b2.Y)-(a1.Y-a2.Y)*(b1.X-b2.X);
        ll da=a2.X-a1.X;
        ll db=b2.X-b1.X;
        ll pa=a2.Y-a1.Y;
        ll pb=b2.Y-b1.Y;
        if(da*pb!=db*pa){
            assert(lb(x)/lb(m)==lb(l));
            cout<<l<<" "<<lb(y)/lb(m);
        }
        else{
            if(r==l){
                assert(round(a_data)==round(b_data));
                cout<<l<<" "<<round(a_data);
            }
        }
    }
}
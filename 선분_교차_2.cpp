#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
int cmp(pair<ll,ll>a,pair<ll,ll>b){
	ll x=a.X*a.Y*b.Y;
	ll y=b.X*a.Y*b.Y;
	//cout<<x<<" "<<y<<"\n";
	if(x==y) return 0;
	else if(x>y) return 1;
	else return -1;
}
bool check(ll x1,ll x2,ll y1,ll y2,ll kx,ll ky){
    if(kx<x1 or x2<kx) return false;
    if(y1==y2){
        if(ky==y1) return true;
        else return false;
    } 
    if(x1==x2){
        if(min(y2,y1)<=ky and ky<=max(y1,y2)) return true;
        else return false;
    }
    //(y2-y1)/(x2-x1)*(kx-x1)
    if((x2-x1)*(kx-x1)==0) return false;
    if(y1<y2){
        return false;
        ky+=(y2-y1)/((x2-x1)*(kx-x1));
        int res=(y2-y1)%((x2-x1)*(kx-x1));
        if(ky<y1 or y2<ky) return false;
        if(ky==y2 and res) return false;
        return true;
    }
    else{
        return false;
        ky-=(y1-y2)/((x2-x1)*(kx-x1));
        int res=(y1-y2)/((x2-x1)*(kx-x1));
        if(ky<y2 or y1<ky) return false;
        if(ky==y2 and res) return false;
        return true; 
    }
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	int x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	if(x2<x1){
		swap(x1,x2);
		swap(y1,y2);
	}
	if(x4<x3){
		swap(x3,x4);
		swap(y3,y4);
	}
    if(check(x1,x2,y1,y2,x3,y3) or check(x1,x2,y1,y2,x4,y4) or check(x3,x4,y3,y4,x1,y1) or check(x3,x4,y3,y4,x2,y2)){
        cout<<"1";
        return 0;
    }
	assert(x1<=x2);
	assert(x3<=x4);
	if(x2<x3||x4<x1){cout<<"0";return 0;}
	//float d1=(y2-y1)/(x2-x1);
	pair<ll,ll>d1={y2-y1,x2-x1};
	//assert(d1.Y>0);
	//float d2=(y4-y3)/(x4-x3);
	pair<ll,ll>d2={y4-y3,x4-x3};
	//assert(d2.Y>0);
	int kl=max(x1,x3);
	int kr=min(x2,x4);
	/*y1+=(kl-x1)*d1;
	y2-=(x2-kr)*d1;
	y3+=(kl-x3)*d2;
	y4-=(x4-kr)*d2;*/
	pair<ll,ll>p1={0,1},p2{0,1},p3{0,1},p4{0,1};
	if(x1<kl){
		ll diff=kl-x1;
		y1+=(diff*d1.X)/d1.Y;
		p1={(diff*d1.X)%d1.Y,d1.Y};
	}
	else if(x3<kl){
		ll diff=kl-x3;
		y3+=(diff*d2.X)/d2.Y;
		p2={(diff*d2.X)%d2.Y,d2.Y};
	}
	if(kr<x2){
		ll diff=x2-kr;
		y2-=(diff*d1.X)/d1.Y;
		ll m=(diff*d1.X)%d1.Y;
		//if(m) y2--;
		p3={m,d1.Y};
	}
	else if(kr<x4){
		ll diff=x4-kr;
		y4-=(diff*d2.X)/d2.Y;
		ll m=(diff*d2.X)%d2.Y;
		//if(m) y4--;
		p4={m,d2.Y};
	}
	int c1=-2,c2=-2;
	if(d1.Y==0&&d2.Y==0){
		if(y1>y2) swap(y1,y2);
		if(y3>y4) swap(y3,y4);
		if(y2<y3||y4<y1) cout<<"0";
		else cout<<"1";
		return 0;
	}
	if(d1.Y==0){
		if(y1>y2) swap(y1,y2);
		if(y2==y3&&p2.X==0) cout<<"1";
		else if(y1<=y3&&y3<y2) cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(d2.Y==0){
		if(y3>y4) swap(y3,y4);
		if(y1==y4&&p1.X==0) cout<<"1";
		else if(y3<=y1&&y1<y4) cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(kr==kl){
		if(y1==y3&&cmp(p1,p2)==0) cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(y1<y3) c1=-1;
	else if(y1>y3) c1=1;
	else{
		c1=cmp(p1,p2);
		//cout<<"cmp :"<<c1<<"\n";
	}
	if(y2<y4) c2=-1;
	else if(y2>y4) c2=1;
	else{
		c2=cmp(p4,p3);
	}
	//cout<<"1 : "<<y1<<" "<<y2<<"\n";
	//cout<<"2 : "<<y3<<" "<<y4<<"\n";
	//cout<<"p1 : "<<p1.X<<" "<<p1.Y<<"\n";
	//cout<<"p2 : "<<p2.X<<" "<<p2.Y<<"\n";
	//cout<<c1<<" "<<c2<<"\n";
	if(c1==0||c2==0) cout<<"1";
	else if(c1+c2==0) cout<<"1";
	else cout<<"0";
}
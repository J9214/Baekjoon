#include<cstdio>
int a,i,n;int main(){char c[100001],b;scanf("%s",c);for(;c[i];i++){if(c[i]==40)n++;else{n--;if(b==41)a++;else a+=n;}b=c[i];}printf("%d",a);}
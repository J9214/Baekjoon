// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	while(cin>>str){
        char p=0, pp=0;
		bool b = 1,cnt=0;
		if(str=="end")break;
		for(char c : str){
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') cnt = 1;
			if(c<=90)b=0;
			if(p==c && !(c == 'e' || c=='o')) b=0;
			if(pp != 0 &&(((c=='a'||c=='e'||c=='o'||c=='i'||c=='u')
			 && (p=='a'||p=='e'||p=='o'||p=='i'||p=='u')
			  && (pp=='a'||pp=='e'||pp=='o'||pp=='i'||pp=='u')) || 
			  (!(c=='a'||c=='e'||c=='o'||c=='i'||c=='u')
			 && !(p=='a'||p=='e'||p=='o'||p=='i'||p=='u')
			  && !(pp=='a'||pp=='e'||pp=='o'||pp=='i'||pp=='u')))) b=0;	

			if(p!=0)pp=p;
			p=c;	
		}
		cout <<"<" << str << (cnt&&b ? "> is acceptable." : "> is not acceptable.") << '\n';
	}
}

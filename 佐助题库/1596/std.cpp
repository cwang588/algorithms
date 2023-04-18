#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int a[1005],b[1005];
char tmp[10005];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		for(int j=1;j<=100;++j){
			int now=rand()%126+1;
			if(now<=32)now=32;
			tmp[j]=(char)now;
		}
		freopen(s1,"w",stdout);
		for(int j=1;j<=100;++j)cout<<tmp[j];
		cout<<endl;
		freopen(s2,"w",stdout);
		for(int j=1;j<=100;++j)cout<<tmp[j];
		cout<<endl;
	}
	return 0;
}

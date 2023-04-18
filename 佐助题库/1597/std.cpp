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
		int n=1000,m=rand()%n+1;
		freopen(s1,"w",stdout);
		cout<<n<<' '<<m<<endl;
		for(int j=1;j<=n;++j){
			a[j]=rand();
			cout<<a[j]<<' ';
		}
		cout<<endl;
		freopen(s2,"w",stdout);
		for(int j=m;j>=1;--j)cout<<a[j]<<' ';
		for(int j=m+1;j<=n;++j)cout<<a[j]<<' ';
		cout<<endl;
	}
	return 0;
}

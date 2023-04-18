#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int a[1005],b[1005];
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<10;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int m=rand()%1000+1,n=rand()%m+1,k=rand()%n+1;
		freopen(s1,"w",stdout);
		cout<<n<<' '<<m<<' '<<k<<endl;
		for(int j=1;j<=n;++j){
			a[j]=rand();
			cout<<a[j]<<' ';
		}
		cout<<endl;
		for(int j=1;j<=m;++j){
			b[j]=rand();
			cout<<b[j]<<' ';
		}
		cout<<endl;
		freopen(s2,"w",stdout);
		for(int j=1;j<=k;++j)cout<<a[j]<<' ';
		for(int j=k+1;j<=m;++j)cout<<b[j]<<' ';
	}
	return 0;
}
